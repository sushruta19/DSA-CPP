#include<iostream>
#include<cmath>
using namespace std;

//T:O(n2^n)
void printSubsequences(string s)
{
  int n = s.length();
  int numOfSubseq = pow(2,n);
  for(int i=1; i<numOfSubseq; i++)
  {
    for(int j=0; j<n; j++)
    {
      if((1<<j)&i)
        cout<<s[j];
    }
    cout<<endl;
  } 
}

int main()
{
  printSubsequences("abc");
}