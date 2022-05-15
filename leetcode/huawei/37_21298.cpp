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

bool is_same_char(char a, char b)
{
	//cout << "1 a: " << a << ", b: " << b << endl;
    if(a >= 'A' && a <= 'Z') a = 'a' + a - 'A';
    if(b >= 'A' && b <= 'Z') b = 'a' + b - 'A';
	//cout << "1 a: " << a << ", b: " << b << endl;
    return a == b;
}
int get_comm_str_len(string &s1, string &s2)
{
	int ans = 0;
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(is_same_char(s1[i], s2[j]))
            {
            	if(i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
            }
        }
    }
	//print(dp);
	return ans;
}
int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        cout << get_comm_str_len(s1, s2) << endl;
    }
}
