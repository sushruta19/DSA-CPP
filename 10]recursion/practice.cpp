#include<bits/stdc++.h>
using namespace std;

// void summation(int n, int sum)
// {
//   if(n<1)
//   {
//     cout<<sum<<endl;
//     return;
//   }
//   summation(n-1, sum+n);
// }

// void summation(int i, int j)
// {
//   if(n<1)
//     return;
//   summation(n-1);

// }
int factorial(int n)
{
  if(n==0)return 1;
  return n*factorial(n-1);
}

void factorial(int n, int temp=1)
{
  if(n==0)
  {
    cout<<temp;
    return;
  }
  factorial(n-1, temp*n);
}

void reverse(int a, int temp=0)
{
  if(a<1)
  {
    cout<<temp;
    return;
  }
  temp = temp*10 + a%10;
  reverse(a/10, temp);
}

// bool isPalindrome(string s, int i)
// {
//   if(i>=s.length()/2)return true;
//   if(s[i]!=s[s.length()-1-i])return false;
//   return isPalindrome(s, i+1);
// }

//T:O(2^n)
int fibonacci(int n)
{
  if(n==1)
    return 0;
  if(n==2)
    return 1;
  return fibonacci(n-1)+fibonacci(n-2);
}

void printSubseq(int i, vector<int>subseq)
{
  if(i >= n)
}

int main()
{
  printSubsequences("abc");
}
