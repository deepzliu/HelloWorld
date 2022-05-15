#include <iostream>
#include <stack>
using namespace std;

int get_result(string & s)
{
	int ans = 0;
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
				ans++;
				st.pop();
			}
			else
			{
				ans = 0;
				break;
			}
		}
		else if(s[i] == ']')
		{
			if(st.size() > 0 && st.top() == '[')
			{
				ans++;
				st.pop();
			}
			else
			{
				ans = 0;
				break;
			}
		}
		else if(s[i] == '}')
		{
			if(st.size() > 0 && st.top() == '{')
			{
				ans++;
				st.pop();
			}
			else
			{
				ans = 0;
				break;
			}
		}
	}
	if(st.size() > 0)
	{
		ans = 0;
	}
	return ans;
}

int main()
{
	string s;
	while(cin >> s)
	{
		cout << get_result(s) << endl;
	}
}

