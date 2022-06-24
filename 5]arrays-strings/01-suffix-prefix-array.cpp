#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cmath>     //pow()
using namespace std;
typedef long long int lli;

//prefix sum array
void prefixSumArray(int a[], int n)
{
  int prefix[n];
  prefix[0] = a[0];
  for(int i=1;i<n;i++)
  {
    prefix[i] = a[i]+prefix[i-1];
  }
  for(int i=0; i<n; i++)
    cout<<prefix[i]<<" ";
}

//suffix sum array
void suffixSumArray(int a[], int n)
{
  int suffix[n];
  suffix[n-1] = a[n-1];
  for(int i=n-2; i>=0; i--)
  {
    suffix[i] = a[i] + suffix[i+1];
  }
  for(int i=0;i<n;i++)
    cout<<suffix[i]<<" ";
}


//Driver Code
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9};
  int n = sizeof(a)/sizeof(a[0]);
  prefixSumArray(a,n);
  cout<<endl;
  suffixSumArray(a,n); 
}

