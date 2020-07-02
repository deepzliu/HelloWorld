#include <iostream>
#include <vector>

using namespace std;

int test1()
{
	vector<vector<int>> v(10, vector<int>(10, 5));
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int test2()
{
	vector<vector<int>> v(10, vector<int>());
	for(int i = 0; i < v.size(); i++)
	{
		v[i].push_back(1);
		v[i].push_back(2);
	}
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	test2();
}
