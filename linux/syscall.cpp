#include<iostream>
using namespace std;

int main()
{
	int tid = syscall(SYS_gettid); 
	cout << "tid: " << tid << endl;
}
