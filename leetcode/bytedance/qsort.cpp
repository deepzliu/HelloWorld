#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector<int> &v, int left, int right);
void printv(vector<int> & v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    //v.push_back(5);
    //v.push_back(2);
    //v.push_back(1);
    //v.push_back(4);
    //v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    //v.push_back(5);
    //v.push_back(4);
    //v.push_back(3);
    //v.push_back(2);
    //v.push_back(1);
    printv(v);
    quick_sort(v, 0, v.size() - 1);
    printv(v);
}

void quick_sort(vector<int> &v, int left, int right)
{
    if(left >= right) return;
    int start = left;
    int end = right;
    int &p = v[left];
	cout << "1 left: " << left << ", right: " << right << ", start: " << start << endl;
    while(start < end)
    {
        if(v[start] >= p)
        {
            while(start < end && v[end] >= p) end--;
            swap(v[start], v[end]);
        }
        else 
        {
            start++;
        }
    }
    if(start > left && v[start] <= p) swap(p, v[start]);

	cout << "2 left: " << left << ", right: " << right << ", start: " << start << endl;
	printv(v);
    
    quick_sort(v, left, start - 1);
    quick_sort(v, start + 1, right);
}
