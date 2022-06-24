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

//function to rearrange sorted array in max, min, 2ndmax, 2ndmin, ... form.
//T:O(n) AS:O(n)
void rearrange(int a[], int n)
{
  int temp[n];
  for(int i=0;i<n;i++)
    temp[i]=a[i];
  int low=0, high=n-1;
  for(int i=0;i<n;i++)
  {
    if(i%2==0)
      a[i] = temp[high--];
    else
      a[i] = temp[low++];
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

//optimising the rearrange function by storing two numbers at one index
//Quite tricky
//T:O(n) AS:O(1)
void rearrange2(int a[], int n)
{
  int max_element = a[n-1]+1;
  int max_index = n-1, min_index = 0;

  for(int i=0;i<n;i++)
  {
    if(i%2==0)  //putting max element
    {
      a[i] = a[i] + (a[max_index]%max_element)*max_element;
      max_index--;
    }
    else
    {
      a[i] = a[i] +(a[min_index]%max_element)*max_element;
      min_index++;
    }
  }
  for(int i=0;i<n;i++)
    cout<<a[i]/max_element<<" ";
}
//url:(https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/)

//Driver Code
int main()
{
  int a[]={1,2,3,4,5,6};
  int n = sizeof(a)/sizeof(a[0]);
  rearrange2(a,n);
}


