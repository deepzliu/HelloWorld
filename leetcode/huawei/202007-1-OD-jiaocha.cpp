#include <iostream>
#include <stack>
using namespace std;

int get_result(string & s)
{
	//int ans = 0;
	int err = 0;
	int n1 = 0, n2 = 0, n3 = 0;
	stack<char> st1;
	stack<char> st2;
	stack<char> st3;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '<')
		{
			st1.push(s[i]);
		}
		else if(s[i] == '[')
		{
			st2.push(s[i]);
		}
		else if(s[i] == '{')
		{
			st3.push(s[i]);
		}
		else if(s[i] == '>')
		{
			if(st1.size() > 0 && st1.top() == '<')
			{
				n1 = 1;
				st1.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
		else if(s[i] == ']')
		{
			if(st2.size() > 0 && st2.top() == '[')
			{
				n2 = 1;
				st2.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
		else if(s[i] == '}')
		{
			if(st3.size() > 0 && st3.top() == '{')
			{
				n3 = 1;
				st3.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
	}
	if(err > 0 || st1.size() > 0 || st2.size() > 0 || st3.size() > 0)
	{
		return 0;
	}
	return n1+n2+n3;
}

int main()
{
	string s;
	while(cin >> s)
	{
		cout << get_result(s) << endl;
	}
}

