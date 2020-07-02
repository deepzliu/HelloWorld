#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int last_slash = -1, next_slash = -1;
		stack<string> valid_path;
		string name;

		for(int i = 0; i < path.size(); i++)
		{
			if(path[i] != '/' && i != path.size() - 1)
			{
				continue;
			}

			if(i == path.size() - 1 && path[i] != '/')
			{
				i++;
			}

			if(last_slash == -1 && i == 0)
			{
				last_slash = 0;
				continue;
			}
			else if(last_slash == -1 && i > 0)
			{
				name = path.substr(0, i - 1);
			}
			else
			{
				name = path.substr(last_slash+1, i - last_slash - 1);
			}
			last_slash = i;

			if(name == "." || name.empty())
			{
				continue;
			}
			else if(name == "..")
			{
				if(!valid_path.empty())
				{
					valid_path.pop();
				}
			}
			else
			{
				valid_path.push(name);
			}
		}

		if(valid_path.empty())
		{
			return "/";
		}

		string result;
		while(!valid_path.empty())
		{
			result = "/" + valid_path.top() + result;
			cout << "element: " << valid_path.top() << ", result: " << result << endl;
			valid_path.pop();
		}

		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution so;
	cout << "[result] " << so.simplifyPath(argv[1]) << endl;
}

