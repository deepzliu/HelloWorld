// ## 请在下方描述你的面试题内容( 支持Markdown )

// /*
// 题目：给定两个有序整数数组 A 和 B，数组内元素可能重复，求出那些在 A 中但是不在 B 中的元素。

// 例子：
// A: [1, 3, 5, 5, 6, 8, 9]
// B: [2, 3, 5, 7]
// 结果：[1, 6, 8, 9]
// */

// 你必须定义一个 `main()` 函数入口。
#include <iostream>
#include <vector>
using namespace std;
vector<int> getOnlyA(vector<int> &A, vector<int> &B)
{
  vector<int> res;
  int i = 0, j = 0;
  while(i < A.size())
  {
    if(j == B.size() - 1)
    {
      res.push_back(A[i]);
      i++;
      continue;
    }
    
    if(A[i] == B[j])
    {
      while(i+1 < A.size() && A[i] == A[i+1]) i++;
      i++;
      while(j+1 < B.size() && B[j] == B[j+1]) j++;
      j++;
    }
    else if(A[i] < B[j])
    {
      res.push_back(A[i]);
      while(i+1 < A.size() && A[i] == A[i+1]){
        res.push_back(A[i]);
        i++;
      } 
      i++;
    }
    else
    {
      while(j+1 < B.size() && B[j] == B[j+1]) j++;
      j++;
    }
  }
  return res;
}
int main()
{
    vector<int> A{1, 1, 3, 5, 5, 6, 6, 7, 8, 9, 9, 9};
    vector<int> B{2, 2, 3, 5, 7, 7};
    vector<int> res = getOnlyA(A,B);
    for(int i = 0; i < res.size(); i++)
    {
      cout  << res[i] << " ";
    }
    cout << endl;
    return 0;
}

