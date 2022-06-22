#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cmath>     //pow()
using namespace std;
typedef int64_t lli;

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

//function to return equilibrium point(index), i.e., the sum of all elements to its left
//should be equal to sum of all elements to its right. If such point doesn't exist, return -1
//T:O(n) AS:O(1)
lli equilibriumPoint(lli a[], lli n)
{
  if(n==1)      //leftSum and rightSum is 0, hence the single element will itself be the eq point
    return 0;
  if(n==2)      //arr having 2 elements cannot have an eq point
    return -1;

  lli leftSum=0, rightSum=0, low=0, high=n-1;
  //keep adding leftSum and rightSum until all the elements have been added(except the eq point)
  while(low!=high)
  {
    if(leftSum<rightSum)    
      leftSum+=a[low++];
    else if(rightSum<leftSum)
      rightSum+=a[high--];
    else                      //leftSum == rightSum but the elements to be added are still left, so loop will continue
      rightSum+=a[high--];    //let us add to the rightSum(we could also have added leftSum)
  }
  if(leftSum == rightSum)     
    return low;
  else
    return -1;
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

