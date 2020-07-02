#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(x == 0) return 0;
		const double WUCHA = 0.00001;
        double left = 1, right = x;
        double target = 0, diff = 0;
        do{
            target =  (double)(right + left)/2;
            diff = (double)(x - target*target);

			cout << "left: " << left << ", right: " << right 
				 << ", target: " << target << ", diff: " << diff << endl;

            if(fabs(diff) < WUCHA) break;
            if(diff > 0) left = target;
            else right = target;
            //if((int)left == (int)right){
            //    //target = left;
            //    break;
            //}
        }while(true);
        return (int)(target+WUCHA);
    }
};

int main(int argc, char *argv[])
{
	int num = atoi(argv[1]);
	Solution so;
	cout << so.mySqrt(num) << endl;
}
