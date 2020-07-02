#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix;
		if(strs.size() == 0)
		{
			return prefix;
		}
		else if(strs.size() == 1)
		{
			return strs[0];// not sure
		}

		int right_pos = 0;
		bool no_more = false;
		char right_char;
		while(true)
		{
			if(strs[0].size() < right_pos + 1)
			{
				break;
			}
			cout << "pos: " << right_pos << ", char: " << right_char << endl;
			right_char = strs[0][right_pos];
			for(int i = 1; i < strs.size(); i++)
			{
				if(strs[i].size() < right_pos + 1 || right_char != strs[i][right_pos])
				{
					no_more = true;
					break;
				}
			}

			if(no_more)
			{
				break;
			}

			right_pos++;
		}

		return strs[0].substr(0, right_pos);
    }
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<string> strs;
	for(int i = 1; i < argc; i++)
	{
		strs.push_back(argv[i]);
		cout << "i: " << argv[i] << endl;
	}
	cout << "strs size: " << strs.size() << endl << endl;

	cout << so.longestCommonPrefix(strs) << endl;
}
