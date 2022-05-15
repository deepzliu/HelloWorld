#include <iostream>
#include <vector>
using namespace std;

int get_result(vector<int> &nums)
{
	int ans = 0;
	vector<int> dp(nums.size(), 1);
	for(int i = 1; i < nums.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	int num = 0;
	vector<int> nums;
	while(cin >> num)
	{
		nums.resize(num);
		for(int i = 0; i < num; i++)
		{
			cin >> nums[i];
		}
		cout << get_result(nums) << endl;
	}
}
