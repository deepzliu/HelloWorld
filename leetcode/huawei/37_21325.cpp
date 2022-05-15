#include <iostream>
#include <vector>
using namespace std;

string get_result(const string & s)
{
	vector<int> n(129, 0);
	for(int i = 0; i < s.size(); i++)
	{
		n[s[i]]++;
	}

	int imax = 0, idx = -1;
	int res_cnt = 0;
	string res(129, 0);
	while(true)
	{
		for(int i = 0; i < 129; i++)
		{
			if(n[i] > imax)
			{
				imax = n[i];
				idx = i;
			}
		}
		if(idx == -1) break;
		res[res_cnt++] = idx;
		n[idx] = 0;
		imax = 0;
		idx = -1;
	}
	res.resize(res_cnt);
	return res;
}

int main()
{
	string s;
	while(cin >> s)
	{
		cout << get_result(s) << endl;
	}
}

