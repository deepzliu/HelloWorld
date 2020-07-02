#include <iostream>
#include <vector>
//#include <map>
//#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int head = 0;
		int tail = nums.size() - 1;

		return bsearch(nums, head, tail, target);
    }

	int bsearch(vector<int>& nums, int head, int tail, int target)
	{
		//cout << "bsearch: " << head << ", " << tail << endl;
		if(head > tail || tail < 0)
		{
			//cout << "[1 -1]" << endl;
			return -1;
		}
		if(target == nums[head]) return head;
		if(target == nums[tail]) return tail;
		if(head == tail)
		{
			//cout << "[2 -1]" << endl;
 			return -1;
		}

		int mid  = (head + tail) / 2;
		if(nums[mid] == target)
		{
			return mid;
		}

		if(nums[mid] > nums[tail]) // out-of-order in lower half
		{
			if(nums[head] < target && target < nums[mid])
			{
				return bsearch(nums, head + 1, mid - 1, target);
			}
			else if(!(target < nums[mid] && target > nums[tail]))
			{
				return bsearch(nums, mid + 1, tail - 1, target);
			}
			else
			{
				//cout << "[3 -1]" << endl;
				return -1;
			}

		}
		else if(nums[head] > nums[mid]) // out-of-order in front half
		{
			if(nums[mid] < target && target < nums[tail])
			{
				return bsearch(nums, mid + 1, tail - 1, target);
			}
			else if(!(target < nums[head] && target > nums[mid]))
			{
				return bsearch(nums, head + 1, mid - 1, target);
			}
			else
			{
				//cout << "[4 -1]" << endl;
				return -1;
			}
		}
		else // in-order
		{
			if(nums[head] < target && target < nums[mid])
			{
				return bsearch(nums, head + 1, mid - 1, target);
			}
			else if(nums[mid] < target && target < nums[tail])
			{
				return bsearch(nums, mid + 1, tail - 1, target);
			}
			else
			{
				//cout << "[5 -1]" << endl;
				return -1;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<int> nums;
	int target = 0;
	for(int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		if(i == argc - 1)
		{
			target = num;
		}
		else
		{
			nums.push_back(num);
		}
	}
	cout << so.search(nums, target) << endl;
}
