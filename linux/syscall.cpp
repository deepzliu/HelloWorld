#include<iostream>
using namespace std;

#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	int tid = syscall(SYS_gettid); 
	cout << "tid: " << tid << endl;
}
