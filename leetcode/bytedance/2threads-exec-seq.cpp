#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// A, B, C, D -> 1, 2, 3, 4
// E, F, G, H -> 5, 6, 7, 8
vector<vector<int>> graph = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
		{0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
		{0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
		{0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

vector<char> c_map = {0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 0};

bool can_access(int n, vector<int> & accessed)
{
	if(accessed[n] == 1) return false;

	if(n <= 4)
	{
		for(int i = 1; i < n; i++)
		{
			if(accessed[i] == 0) return false;
		}
	}
	else
	{
		for(int i = 5; i < n; i++)
		{
			if(accessed[i] == 0) return false;
		}
	}
	return true;
}

void dfs(int n, vector<int> & accessed, vector<int> & result, int & res_len)
{
	accessed[n] = 1;
	result[res_len++] = n;

	if(res_len == 8)
	{
		for(int i = 0; i < res_len; i++)
		{
			cout << c_map[result[i]] << " ";
		}
		cout << endl;
	}
	else
	{
		for(int i = 1; i <= 8; i++)
		{
			if(graph[n][i] == 1 && can_access(i, accessed))
			{
				dfs(i, accessed, result, res_len);
			}
		}
	}

	// 回溯
	res_len--;
	accessed[n] = 0;
}

void exec_order()
{
	vector<int> accessed(10, 0);
	vector<int> result(8, 0);
	int res_len = 0;

	// start from A
	dfs(1, accessed, result, res_len);
	
	// start from E
	dfs(5, accessed, result, res_len);
}

int main()
{
	exec_order();
}
