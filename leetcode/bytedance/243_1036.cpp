#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int circle = 0;
        vector<char> search_flags(M.size(), 0);
		queue<int> search_queue;
		for(int i = 0; i < M.size(); i++)
		{
			if(search_flags[i] == 1) continue;
			search_flags[i] = 1;
			circle++;
			search_queue.push(i);

			while(!search_queue.empty())
			{
				int one = search_queue.front();
				search_queue.pop();
				for(int j = 0; j < M[one].size(); j++)
				{
					if(search_flags[j] == 1) continue;

					if(M[one][j] == 1)
					{
						search_flags[j] = 1;
						search_queue.push(j);
					}
				} // for
			} // while
		} // for

		return circle;
    }
};

int main(int argc, char *argv[])
{
	Solution so;
    vector<vector<int>> M;
	vector<int> N;
	int n = sqrt(argc - 1);
	int m = 1;
	for(int i = 0; i < n; i++)
	{
		N.clear();
		for(int j = 0; j < n; j++)
		{
			int num = atoi(argv[m]);
			cout << num << " ";
			N.push_back(num);
			m++;
		}
		cout << endl;
		M.push_back(N);
	}
	cout << "result: " << so.findCircleNum(M) << endl;

	cout << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}
