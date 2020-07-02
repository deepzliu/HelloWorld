#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

// 0! - 9!
int FACTORIAL[10] = 
{
	0, 1, 2, 6,
	24, 120, 720,
	5040, 40320, 362880
};

class Solution {
public:
    string getPermutation(int n, int k) {
		string num;

		int pos = 1;
		vector<int> permutation(n+1, 1); // permutation position
		getSub(permutation, pos, n, k);
		
		vector<int> tag(n+1, 0);
		//cout << "permutation: ";
		for(int i = 1; i <= n; i++)
		{
			int & m = permutation[i];
			//cout << m << " ";
			pos = 0;
			for(int j = 1; j <= n; j++)
			{
				if(tag[j] == 0)
				{
					pos++;
					if(pos == m)
					{
						num += ('0' + j);
						tag[j] = 1;
					}
				}

			}
		}
		//cout << endl;

		return num;
    }

	void getSub(vector<int> & permutation, int & pos, int n, int k)
	{
		if(n == 1) return;

		int flag = 0;
		if(k == FACTORIAL[n])
		{
			//cout << "equal" << endl;
			permutation[pos] = n;
			flag = 1;
		}
		else if(k > FACTORIAL[n-1] && k < FACTORIAL[n])
		{
			//cout << "smaller" << endl;
			permutation[pos] = (k + FACTORIAL[n-1] - 1) / FACTORIAL[n-1];
			flag = 1;
		}

		//cout << "pos: " << pos << ", n: " << n << ", k: " << k 
		//	 << ", permutation: " << permutation[pos] << endl;

		if(flag == 1)
		{
			if(k > FACTORIAL[n-1] && k % FACTORIAL[n-1] == 0)
			{
				//cout << "special, k: " << k << ", FACTORIAL[n]: " << FACTORIAL[n] << endl;
				k = FACTORIAL[n-1];
			}
			else
			{
				k = k % FACTORIAL[n-1];
			}
		}

		pos++;
		n--;

		if(k > 1)
		{
			getSub(permutation, pos, n, k);
		}
	}

};

int main(int argc, char *argv[])
{
	Solution so;
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	cout << so.getPermutation(n, k) << endl;

}
