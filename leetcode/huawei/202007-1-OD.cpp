#include <iostream>
#include <stack>
using namespace std;

int get_result(string & s)
{
	int err = 0;
	int n1 = 0, n2 = 0, n3 = 0;
	stack<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '<' || s[i] == '[' || s[i] == '{')
		{
			st.push(s[i]);
		}
		else if(s[i] == '>')
		{
			if(st.size() > 0 && st.top() == '<')
			{
				n1 = 1;
				st.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
		else if(s[i] == ']')
		{
			if(st.size() > 0 && st.top() == '[')
			{
				n2 = 1;
				st.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
		else if(s[i] == '}')
		{
			if(st.size() > 0 && st.top() == '{')
			{
				n3 = 1;
				st.pop();
			}
			else
			{
				err = 1;
				break;
			}
		}
	}
	if(st.size() > 0 || err > 0)
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

