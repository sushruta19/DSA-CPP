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

//function to return equilibrium point(index, 0-based indexing), i.e., the sum of all elements to its left
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

//Driver Program
int main()
{
  lli a[] = {1,5,9,1,2,8,8};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"equilibrium point is "<<equilibriumPoint(a,n)<<endl;
}