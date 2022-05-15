#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}
int get_result(int n, int m)
{
	int ans = 0;
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i == 0 && j == 0) continue;
			if(i == 0) dp[i][j] = dp[i][j-1];
			else if(j == 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	print(dp);
	return dp[n][m];
}

int main()
{
	int n, m;
    while(cin >> n >> m)
    {
		cout << get_result(n, m) << endl;
	}
}
