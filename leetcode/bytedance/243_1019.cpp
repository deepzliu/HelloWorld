#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        unordered_set<int> nums_set;
        unordered_set<int> nums_used;

        for(int i = 0; i < nums.size(); i++)
        {
            nums_set.insert(nums[i]);
        }

        int n = 0;
        int sub_longest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            n = nums[i];
            nums_used.insert(n);
            sub_longest = 1;
			//cout << "[seq start]: " << n << endl;
            while(true) // find bigger
            {
				n++;
				//cout << "find seq next: " << n << endl;
                if(nums_set.find(n) != nums_set.end() 
                   && nums_used.find(n) == nums_used.end())
                {
                    sub_longest++;
                    nums_used.insert(n);
					//cout << "got seq next: " << n << ", sub_longest: " << sub_longest << endl;
                }else
				{
                	break;
				}
            }

			n = nums[i];
            while(true) // find smaller
            {
				n--;
				//cout << "find seq prev: " << n << endl;
                if(nums_set.find(n) != nums_set.end() 
                   && nums_used.find(n) == nums_used.end())
                {
                    sub_longest++;
                    nums_used.insert(n);
					//cout << "got seq prev: " << n << ", sub_longest: " << sub_longest << endl;
                }else
				{
                	break;
				}
            }
            longest = sub_longest > longest ? sub_longest : longest;
        }

        return longest;
    }        

    int longestConsecutive2(vector<int>& nums) {

		int n = 0, longest = 0;
		map<int, vector<int>> seqs_map;
		map<int, vector<int>>::iterator seq_it;
		for(int i = 0; i < nums.size(); i++)
		{
			int & n = nums[i];
			seq_it = seqs_map.find(n - 1);
			if(seq_it != seqs_map.end())
			{
				seq_it->second.push_back(n);
				seqs_map.insert(pair<int, vector<int>>(n, move(seq_it->second)));
				seqs_map.erase(seq_it);
				longest = longest > seq_it->second.size() ? longest : seq_it->second.size();
			}
			else
			{
				seqs_map.insert(pair<int, vector<int>>(n, vector<int>(1, n)));
				longest = longest > 1 ? longest : 1;
			}
		}

		return longest;
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
	}
	cout << so.longestConsecutive(nums) << endl;

	/*for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;*/
}
