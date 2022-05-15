#include <iostream>
#include <vector>
using namespace std;

bool get_result(vector<int> &nums, vector<bool> &flags, int sum5, int sum3)
{
    bool ans = false;
	for(int i = 0; i < nums.size(); i++)
	{
		if(flags[i] == true) continue;
		flags[i] = true;
		ans = get_result(nums, flags, sum5+nums[i], sum3);
		if(ans == true) return true;
		ans = get_result(nums, flags, sum5, sum3+nums[i]);
		if(ans == true) return true;
		flags[i] = false;
	}

	if(sum5 == sum3) return true;

    return false;
}

void print(vector<int> & nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main()
{
    int num = 0, n = 0;
	int sum5 = 0, sum3 = 0;
    vector<int> nums;
	vector<bool> flags;
    while(cin >> num)
    {
        nums.clear();
		sum5 = 0, sum3 = 0;
        for(int i = 0; i < num; i++)
        {
            cin >> n;
			if(n % 5 == 0) sum5 += n;
			else if(n % 3 == 0) sum3 += n;
			else nums.push_back(n);
        }

		//print(nums);
		//cout << "sum5: " << sum5 << ", sum3: " << sum3 << endl;


		flags.resize(nums.size(), false);
        if(get_result(nums, flags, sum5, sum3)) cout << "true" << endl;
		else cout << "false" << endl;
    }
}
