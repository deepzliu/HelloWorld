#include <iostream>
using namespace std;

bool is_zishoushu(int num)
{
    int square = num * num;
    cout << "num: " << num << ", square: " << square;
    while(num > 0)
    {
		if(num%10 != square%10){
    		cout << endl;
			return false;
		} 
        num /= 10;
        square /= 10;
    }
    cout << ", it's zishoushu." << endl;
    return true;
}
int get_result(int num)
{
    int ans = 0;
    for(int i = 0; i <= num; i++)
    {
        if(is_zishoushu(i)) ans++;
    }
    return ans;
}

int main()
{
    int num = 2000;
    //while(cin >> num)
    {
        cout << get_result(num) << endl;
    }
}
