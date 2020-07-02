#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		int head = 0;
		int tail = nums.size() - 1;
		return find_k(nums, head, tail, k);
    }

	int find_k(vector<int> & nums, int head, int tail, int k)
	{
	    if(head >= tail)
		{
			if(head + 1 == k) return nums[head];
			else return -1;
		}
	
	    int left = head, right = tail;
	    int& key = nums[right]; // 为什么用第一个元素不行？   
	    while(left < right)
	    {
	        while(left < right && nums[left] >= key)
	        {
	            ++left;
	        }
	        while(left < right && nums[right] <= key)
	        {
	            --right;
	        }
	        swap(nums[left],nums[right]);
	    }
	    swap(nums[left],key);

		if(left + 1 == k) return nums[left];
		else if(left + 1 > k) return find_k(nums,head,left - 1, k);
		else return find_k(nums,left + 1,tail, k);
	}

};

int main(int argc, char *argv[])
{
	Solution so;
	vector<int> nums;
	int k = 0;
	for(int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		if(i == argc - 1)
		{
			k = num;
		}
		else
		{
			nums.push_back(num);
		}
	}
	cout << so.findKthLargest(nums, k) << endl;

	//cout << "qsort: " << endl;
	//so.findKthLargest(nums);
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

