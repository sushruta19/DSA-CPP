#include<iostream>
#include<vector>
using namespace std;

//returning number of subsequences whose sum is k
//T:O(2^n) AS:O(1)
int countKsumSubseq(int ind, int sum, vector<int>& arr, int k) {
  if(ind == (int)arr.size())
  {
    if(sum == k)
      return 1;
    return 0;
  }
  sum+=arr[ind];
  int l = countKsumSubseq(ind+1,sum,arr,k);

  sum-=arr[ind];
  int r = countKsumSubseq(ind+1,sum, arr, k);

  return l+r;
}

int main()
{
  vector<int> arr;
  int n,k; cin>>n>>k;
  for(int i=0; i<n; i++)
  {
    int a; cin>>a;
    arr.push_back(a);
  }
  
  cout<<"Count: "<<countKsumSubseq(0,0,arr,k);
}

