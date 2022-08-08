#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> a)
{
  for(auto x : a)
    cout<<x<<" ";
  cout<<endl;
}


//printing subsequences whose sum is k
//T:O(2^n) AS:O(n)
//recursive method
void printKsumSubseq(vector<int>& subSeq, int i, int sum, vector<int> arr, int k)
{
  if(i >= (int)arr.size())
  {
    if(sum == k)
      print(subSeq);
    return;
  }
  sum+=arr[i];
  subSeq.push_back(arr[i]);
  printKsumSubseq(subSeq,i+1,sum,arr,k);

  sum-=arr[i];
  subSeq.pop_back();
  printKsumSubseq(subSeq,i+1,sum,arr,k);
}
//To print them in reverse, add the last call just after the base case

int main()
{
  vector<int> seq;
  int n,k; cin>>n>>k;
  for(int i=0; i<n; i++)
  {
    int a; cin>>a;
    seq.push_back(a);
  }
  vector<int> subSeq;
  printKsumSubseq(subSeq,0,0,seq,k);
}