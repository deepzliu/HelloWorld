#include <iostream>
using namespace std;

int main()
{
	int num = 0, sum = 0;
	int cnt1 = 0, cnt2 = 0;
	while(cin >> num)
	{
		if(num > 0)
		{
			cnt1++;
			sum += num;
		}
		else if(num < 0)
		{
			cnt2++;
		}
	}

	float mean = 0.0;
	if(cnt1 > 0)
	{
		mean = (float)sum / cnt1;
	}

	printf("%d\n%0.1f\n", cnt2, mean);
	return 0;
}
