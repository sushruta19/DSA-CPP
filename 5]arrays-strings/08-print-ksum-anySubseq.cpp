#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> a) {
  for(auto x : a) {
    cout<<x<<" ";
  }
  cout<<endl;
}

//print any subsequence having sum k
//T:O(2^n) AS:O(n)
bool printAnySubsequence(int ind, vector<int> &ds, int s, int k, int arr[], int n) {
  if(ind >= n) {
    if(s == k) {
      print(ds);
      return true;
    }
    return false;
  }
  
  ds.push_back(arr[ind]);
  s+=arr[ind];

  if(printAnySubsequence(ind+1,ds,s,k,arr,n) == true) {
    return true;
  }

  ds.pop_back();
  s-=arr[ind];

  if(printAnySubsequence(ind+1,ds,s,k,arr,n) == true) {
    return true;
  }
  return false;
}

int main() {
  int n,k; cin>>n>>k;
  int arr[n];
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  vector<int> ds ;
  printAnySubsequence(0,ds,0,k,arr,n);
}

