#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
        int max_len = 0;
		unordered_set<char> sub_chars;
		int left = 0;
        for(int i = 0; i < s.size(); i++)
        {
			while(sub_chars.find(s[i]) != sub_chars.end())
			{
				sub_chars.erase(s[left]);
				left++;
			}
			sub_chars.insert(s[i]);
			max_len = max_len > sub_chars.size() ? max_len : sub_chars.size();
        }
        return max_len;
    }

};

int main(int argc, char *argv[])
{
	Solution so;
	cout << so.lengthOfLongestSubstring(argv[1]) << endl;
}
