#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
	return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
		int a = 0, b = 0;
		vector<vector<int>> results;
		vector<int> elem(2, 0);
		for(int i = 0; i < intervals.size(); i++)
		{
			if(i == 0)
			{
				a = intervals[i][0], b = intervals[i][1];
				continue;
			}

			if(intervals[i][0] > b)
			{
				elem[0] = a, elem[1] = b;
				results.push_back(elem);
				a = intervals[i][0], b = intervals[i][1];
			}
			else if(intervals[i][1] > b)
			{
				b = intervals[i][1];
			}
		}

		// last interval
		if(!(a == 0 && b == 0))
		{
			elem[0] = a, elem[1] = b;
			results.push_back(elem);
		}

		return results;
    }
};

int main(int argc, char *argv[])
{
	Solution so;
    vector<vector<int>> intervals; 
	vector<int> N;
	int n = (argc-1)/2;
	int m = 1;
	for(int i = 0; i < n; i++)
	{
		N.clear();
		for(int j = 0; j < 2; j++)
		{
			int num = atoi(argv[m]);
			cout << num << " ";
			N.push_back(num);
			m++;
		}
		cout << endl;
		intervals.push_back(N);
	}
	
   vector<vector<int>> results = so.merge(intervals);

	cout << endl;
	for(int i = 0; i < results.size(); i++)
	{
		for(int j = 0; j < results[i].size(); j++)
		{
			cout << results[i][j] << " ";
		}
		cout << endl;
	}
}
