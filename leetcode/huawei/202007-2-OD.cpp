#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}
void parse_str(string &s, vector<char> &src, map<int, int> &all, map<char, int> &used)
{
	vector<string> s1 = split(s, '@');
	if(s1.size() == 1) s1.push_back("");
	vector<string> sall = split(s1[0], ',');
	vector<string> sused= split(s1[1], ',');
	vector<string> tmp;
	for(int i = 0; i < sall.size(); i++)
	{
		tmp = split(sall[i], ':');
		if(tmp.size() != 2) continue;
		src.push_back(tmp[0][0]);
		all[src.size() - 1] = atoi(tmp[1].c_str());
	}
	for(int i = 0; i < sused.size(); i++)
	{
		tmp = split(sused[i], ':');
		if(tmp.size() != 2) continue;
		used[tmp[0][0]] = atoi(tmp[1].c_str());
	}
	/*
	for(int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << "-";
	}
	cout << endl; 
	for(auto it = all.begin(); it != all.end(); ++it)
	{
		cout << it->first << "=" << it->second << " - ";
	}
	cout << endl;
	for(auto it = used.begin(); it != used.end(); ++it)
	{
		cout << it->first << "=" << it->second << " - ";
	}
	cout << endl;*/
}

string get_result(string &s)
{
	vector<char> src;
	map<int, int> all;
	map<char, int> used;
	ostringstream res;
	parse_str(s, src, all, used);

	for(auto it = used.begin(); it != used.end(); ++it)
	{
		int pos = 0;
		for(pos = 0; pos < src.size(); pos++)
		{
			if(src[pos] == it->first) break;
		}
		if(pos >= src.size()) continue;
		all[pos] -= it->second;
	}

	int flag = 0;
	for(int pos = 0; pos < src.size(); pos++)
	{
		if(all[pos] > 0)
		{
			if(flag == 0) res << src[pos] << ":" << all[pos];
			else res << "," << src[pos] << ":" << all[pos];
			flag = 1;
		}
	}

	return res.str();
}

int main()
{
	string s;
	while(cin >> s)
	{
		cout << get_result(s) << endl;
	}
}

