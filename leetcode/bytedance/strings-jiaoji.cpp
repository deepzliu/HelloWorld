#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * 空间复杂度：O(n)。假设每个字符串100字节，千万级约1GB，内存能存下
 * 时间复杂度：O(n+m)
*/ 
vector<string> jiaoji(vector<string> &s1, vector<string> &s2)
{
	vector<string> res;
	unordered_set<string> strhash;

	// 将一个集合存入哈希表，用于快速查询
	for(int i = 0; i < s1.size(); i++)
	{
		strhash.insert(s1[i]);
	}

	// 查询交集元素
	for(int i = 0; i < s2.size(); i++)
	{
		if(strhash.find(s2[i]) != strhash.end())
		{
			res.push_back(s2[i]);
		}
	}

	return res;
}

int main()
{
	vector<string> s1;
	s1.push_back("aaa");
	s1.push_back("bbb");
	s1.push_back("ccc");
	s1.push_back("ddd");
	s1.push_back("xxx");

	vector<string> s2;
	s2.push_back("aaa");
	s2.push_back("bbb");
	s2.push_back("ccc");
	s2.push_back("ddd");
	s2.push_back("yyy");

	vector<string> res = jiaoji(s1, s2);
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
