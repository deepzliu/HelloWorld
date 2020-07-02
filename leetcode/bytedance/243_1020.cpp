#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void print_map(map<int, int> & nums_hash)
{
	map<int,int>::iterator it = nums_hash.begin();
	cout << "[map]" << endl;
	for(; it != nums_hash.end(); ++it)
	{
		cout << it->first << " -> " << it->second << endl;
	}
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		vector<int> res(3,0);
		map<int, int> nums_hash;
		for(int i = 0; i < nums.size(); i++)
		{
			nums_hash[nums[i]] += 1;
		}
		//print_map(nums_hash);

		if(nums.size() > 0 && (nums[0] > 0 || nums[nums.size() - 1] < 0))
		{
			return results;
		}

		int sum = 0, remain = 0;
		int last_big_pos = nums.size() - 1;
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = last_big_pos; i < j - 1; j--)
			{
				//cout << "count" << endl;
				sum = nums[i] + nums[j];
				remain = -1 * sum;
				if(sum >= 0)
				{ 
					if(2*nums[i] + nums[j] > 0) // 剪枝
					{
						last_big_pos = j;
						//cout << "[sum>=0] " << i << "=" << nums[i] << ", " << j << "=" << nums[j] << ", last_big_pos: " << last_big_pos << endl;
					}

					if(nums[i+1] <= remain && is_num_exists(nums_hash, nums[i], nums[j], remain))
					{
						// (i, j) from left search -1 * sum
						res[0] = nums[i];
						res[1] = remain;
						res[2] = nums[j];
						if(!is_result_exists(results, res))
						{
							results.push_back(res);
							//cout << i << "=" << nums[i] << ", " << j << "=" << nums[j] << endl;
						}
					}
				}
				else
				{
					if(nums[j-1] >= remain && is_num_exists(nums_hash, nums[i], nums[j], remain))
					{
						// (i, j) from right search
						res[0] = nums[i];
						res[1] = remain;
						res[2] = nums[j];
						if(!is_result_exists(results, res))
						{
							results.push_back(res);
							//cout << i << "=" << nums[i] << ", " << j << "=" << nums[j] << endl;
						}
					}
				}
			}
		}

		return results;
    }

	bool is_num_exists(map<int, int> & nums_hash, int num1, int num2, int target)
	{
		map<int, int>::iterator it = nums_hash.find(target);
		if(it == nums_hash.end())
		{
			return false;
		}
		//cout << "num1: " << num1 << ", num2: " << num2 << ", found: " << target << ", count = " << it->second << endl;
		if(num1 == num2)
		{
			if(it->second >= 3) return true;
		}
		else if(num1 == target || num2 == target)
		{
			if(it->second >= 2) return true;
		}
		else
		{
			return true;
		}
		return false;
	}

	/*bool is_num_exists(vector<int> & nums, int start, int end, int target)
	{
		if(start <= end)
		{
			for(int i = start; i <= end; i++)
			{
				if(nums[i] == target) {
					return true;
				}
			}
		}
		else
		{
			for(int i = start; i >= end; i--)
			{
				if(nums[i] == target) {
					return true;
				}
			}
		}
		return false;
	}*/

	bool is_result_exists(vector<vector<int>> & results, vector<int> res)
	{
		int len = results.size();
		for(int i = len - 1; i >= 0; i--)
		{
			if(results[i][0] != res[0])
			{
				break;
			}
			if(    results[i][0] == res[0] 
				&& results[i][1] == res[1]
				&& results[i][2] == res[2] )
			{
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<int> nums;
	for(int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		nums.push_back(num);
		//cout << i << ", argv: " << argv[i] << ", num: " << num << endl;
	}

	vector<vector<int>> results = so.threeSum(nums);

	for(int i = 0; i < results.size(); i++)
	{
		for(int j = 0; j < results[i].size(); j++)
		{
			cout << results[i][j] << ", ";
		}
		cout << endl;
	}
}

