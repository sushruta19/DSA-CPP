#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//T:O(n2^n)
//Iterative
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

//T:O(2^n)
//Recursive
void printSubsequences2(int i, string output, string input, int n)
{
  if(i>=n)
  {
    cout<<output<<endl;
    return;
  }
  output+=input[i];
  printSubsequences2(i+1, output, input, n);
  output.pop_back();
  printSubsequences2(i+1, output, input, n);
}

int main()
{
  printSubsequences2(0,"","abc",3);
}