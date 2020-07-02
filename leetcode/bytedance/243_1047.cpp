#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		if(height.size() == 0) return 0;
		int result = 0;
		int left = 0, right = height.size() - 1;
		int highest = 0, highest_pos = -1;
		find_highest(height, left, right, highest, highest_pos);

		// from left
		int left_max = height[left]; 
		for(int i = 1; i < highest_pos; i++)
		{
			if(height[i] < left_max)
			{
				result += left_max - height[i];
			}
			else if(height[i] > left_max)
			{
				left_max = height[i];
			}
		}

		// from right
		int right_max = height[height.size() - 1]; 
		for(int i = height.size() - 1; i > highest_pos; i--)
		{
			if(height[i] < right_max)
			{
				result += right_max - height[i];
			}
			else if(height[i] > right_max)
			{
				right_max = height[i];
			}
		}

		return result;
    }

    int find_highest(vector<int>& height, int left, int right, int & highest, int & highest_pos) {
		highest = 0;
		
		for(int i = left; i <= right; i++)
		{
			if(highest <= height[i])
			{
				highest = height[i];
				highest_pos = i;
			}
		}
		return highest;
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<int> v;
	int n = argc;
	for(int i = 1; i < n; i++)
	{
		int num = atoi(argv[i]);
		v.push_back(num);
	}
	
   int result = so.trap(v);

	cout << "result: " << result << endl;
}
