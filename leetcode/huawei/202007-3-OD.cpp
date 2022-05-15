#include <iostream>
//#include <sstream>
#include <map>
#include <vector>
using namespace std;

int delete_node(map<int, vector<int>> &fs, int del)
{
	auto it = fs.find(del);
	if(it == fs.end()) return 0;
	vector<int> &sons = it->second;
	//cout << "delete " << del << ", son size: " << sons.size() << endl;
	for(int i = 0; i < sons.size(); i++)
	{
		delete_node(fs, sons[i]);
	}
	fs.erase(it);
	return 0;
}
bool mycmp(pair<int,int> &a, pair<int,int> &b)
{
	return a.first < b.first;
}

int main()
{
	vector<pair<int,int>> res;
	map<int, vector<int>> fs;
	int num, del;
	int son, dad;
	while(cin >> num)
	{
		for(int i = 0; i < num; i ++)
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
			if(it->first == 0) continue;
			vector<int> &sons = it->second;
			for(int i = 0; i < sons.size(); i++)
			{
				if(sons[i] == del) continue;
				//cout << "=" << sons[i] << " " << it->first << endl;;
				res.push_back(pair<int,int>(sons[i], it->first));
			}
		}
		sort(res.begin(), res.end(), mycmp);
		for(int i = 0; i < res.size(); i++)
		{
			cout << res[i].first << " " << res[i].second << endl;
		}
		fs.clear();
		res.clear();
	}
}

