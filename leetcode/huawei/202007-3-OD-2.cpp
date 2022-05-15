#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int delete_node(map<int, vector<int>> &fs, int del)
{
	auto it = fs.find(del);
	if(it == fs.end()) return 0;
	vector<int> &sons = it->second;
	for(unsigned int i = 0; i < sons.size(); i++)
	{
		delete_node(fs, sons[i]);
	}
	fs.erase(it);
	return 0;
}
bool mycmp(int &a, int &b)
{
	return a < b;
}

int main()
{
	vector<int> res;
	map<int, vector<int>> fs;
	int num, del;
	int son, dad;
	while(cin >> num)
	{
		for(unsigned int i = 0; i < num; i ++)
		{
			cin >> son >> dad;
			auto it = fs.find(dad);
			if(it != fs.end())
			{
				it->second.push_back(son);
			}
			else
			{
				fs.insert(pair<int, vector<int>>(dad, vector<int>(1,son)));
			}
		}
		cin >> del;

		delete_node(fs, del);
		for(auto it = fs.begin(); it != fs.end(); ++it)
		{
			vector<int> &sons = it->second;
			if(it->first != 0) res.push_back(it->first);
			for(unsigned int i = 0; i < sons.size(); i++)
			{
				if(sons[i] == del) continue;
				res.push_back(sons[i]);
			}
		}
		sort(res.begin(), res.end(), mycmp);
		int flag = 0;
		for(unsigned int i = 0; i < res.size(); i++)
		{
			if(i > 0 && res[i] == res[i-1]) continue;
			if(flag == 0) cout << res[i];
			else cout << " " << res[i];
			flag = 1;
		}
		if(flag == 1) cout << endl;
		fs.clear();
		res.clear();
	}
}


