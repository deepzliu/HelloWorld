#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result, mid_result;

		if(num1 == "0" || num2 == "0")
		{
			return "0";
		}

		for(int i = 0; i < num2.size(); i++)
		{
			mid_result = single_multiply(num1, num2[i], num2.size() - i - 1);
			plus(result, mid_result);
		}
		//clear_prefix_0(result);
		return result;
    }

	/*void clear_prefix_0(string & result)
	{
	}*/

	void plus(string & num1, string & num2){
		string result;
		int pos1 = num1.size() - 1;
		int pos2 = num2.size() - 1;
		int inum1 = 0, inum2 = 0;
		int mid_result = 0, carry_bit = 0;

		while(pos1 >= 0 || pos2 >= 0)
		{
			inum1 = 0, inum2 = 0;
			if(pos1 >= 0)
			{
				inum1 = (int)num1[pos1] - '0';
				pos1 --;
			}
			if(pos2 >= 0)
			{
				inum2 = (int)num2[pos2] - '0';
				pos2 --;
			}

			mid_result = inum1 + inum2 + carry_bit;
			carry_bit = mid_result / 10;
			mid_result = mid_result % 10;
			result.push_back(mid_result + '0');
		}

		if(carry_bit > 0)
		{
			result.push_back(carry_bit+ '0');
		}

		reverse(result.begin(),result.end());
		//cout << "left_plus: num1: " << num1 << ", num2: " << num2 << ", result: " << result << endl;

		num1 = result;
	}

	string single_multiply(string &num1, char num2, int tens){
		string result(tens, '0');
		int mid_result = 0, carry_bit = 0;
		int inum1 = 0;
		int inum2 = (int)(num2 - '0');
		for(int i = num1.size() - 1; i >= 0; i--)
		{
			inum1 = (int)(num1[i] - '0');
			mid_result = inum1 * inum2 + carry_bit;
			carry_bit = mid_result / 10;
			mid_result = mid_result % 10;
			result.push_back(mid_result + '0');
			//cout << "inum1: " << inum1 << ", inum2: " << inum2 << ", mid_result: " << mid_result << ", carry_bit: " << carry_bit << ", result: " << result << endl;
		}

		if(carry_bit > 0)
		{
			result.push_back(carry_bit+ '0');
		}

		reverse(result.begin(),result.end());

		//cout << "single_multiply: num1: " << num1 << ", num2: " << num2 << ", tens: " << tens << ", result: " << result << endl;

		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	cout << so.multiply(argv[1], argv[2]) << endl;
}

