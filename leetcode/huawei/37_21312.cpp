#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num_format(string &s, float &n)
{
	if(s.size() > 2) return 1;
	else if(s.size() == 2) n = 10;
	else
	{
		switch(s[0])
		{
			case 'A': n = 1; break;
			case '2': n = 2; break;
			case '3': n = 3; break;
			case '4': n = 4; break;
			case '5': n = 5; break;
			case '6': n = 6; break;
			case '7': n = 7; break;
			case '8': n = 8; break;
			case '9': n = 9; break;
			case 'J': n = 11; break;
			case 'Q': n = 12; break;
			case 'K': n = 13; break;
		}
	}
	return 0;
}

float calc2(float n1, float n2, char op)
{
	float res = 0;
	switch(op)
	{
		case '+': res = n1 + n2; break;
		case '-': res = n1 - n2; break;
		case '*': res = n1 * n2; break;
		case '/': res = n1 / n2; break;
	}
	return res;
}

vector<string> op = {"+", "-", "*", "/"};
vector<string> s(4);
stack<int> res_nums;
stack<int> res_op;
bool calc24impl(vector<float> &nums, vector<bool> &flags, float sum, string &res)
{
	float sum1 = 0;
	bool complete = true;
	for(int i = 0; i < 4; i++)
	{
		if(flags[i] == true) continue;
		complete = false;
		flags[i] = true;
		res_nums.push(i);
		//cout << res_nums.size() << "th num: " << i << " - " << nums[i] << endl;

		for(int j = 0; j < 4; j++)
		{
			res_op.push(j);
			//cout << "op: " << op[j] << endl;
			sum1 = calc2(sum, nums[i], op[j][0]);
			//cout << "sum1: " << sum1 << endl;
			//cout << "0 res_op size: " << res_op.size() << endl;
			if(calc24impl(nums, flags, sum1, res)) return true;
			//cout << "1 res_op size: " << res_op.size() << endl;
			if(res_op.size() > 0) res_op.pop();
			//cout << "2 res_op size: " << res_op.size() << endl;
		}
		//cout << res_nums.size() << "th num end" << endl;
		if(res_nums.size() > 0) res_nums.pop();
		flags[i] = false;
	}
	if(sum == 24)
	{
		vector<string> res1;
		while(res_nums.size() > 0)
		{
			res1.push_back(s[res_nums.top()]);
			res_nums.pop();
			if(res_op.size() > 0)
			{
				res1.push_back(op[res_op.top()]);
				res_op.pop();	
			}
		}
		res = "";
		for(int i = res1.size()-1; i >= 0; i--)
		{
			res += res1[i];
		}
		return true;
	}

	return false;
}

string calc24(vector<float> &nums)
{
	vector<bool> flags(4, false);
	string res = "NONE";
	for(int i = 0; i < 4; i++)
	{
		//cout << "first num: " << i << " - " << nums[i] << endl;
		flags[i] = true;
		res_nums.push(i);
		if(calc24impl(nums, flags, nums[i], res)) break;
		if(res_nums.size() > 0) res_nums.pop();
		flags[i] = false;
		//cout << "first num end" << endl;
	}
	return res;
}

int main()
{
	vector<float> nums(4);
    while(cin >> s[0] >> s[1] >> s[2] >> s[3])
    {
		int err = 0;
		err += num_format(s[0], nums[0]);
		err += num_format(s[1], nums[1]);
		err += num_format(s[2], nums[2]);
		err += num_format(s[3], nums[3]);
		if(err > 0)
		{
			cout << "ERROR" << endl;
			continue;
		}
		stack<int>().swap(res_nums);
		stack<int>().swap(res_op);
		cout << calc24(nums) << endl;
	}
}
