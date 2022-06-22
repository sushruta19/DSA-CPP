#include<iostream>
#include<string>      //substr()
using namespace std;

//Print non-empty substrings of given string
//T:O(n³) AS:O(1)
//Number of substrings of a string of length n is n(n+1)/2
void printSubstrings(string s)
{
  int n = s.length();
  for(int i=0;i<n;i++)
  {
    for(int len = 1;len <= n-i; len++)  //length of substrings starting from index i
    {
      cout<<s.substr(i,len)<<endl;
    }
  }
}

//Optimised way of printing all non empty substrings
//T:O(n²) AS:O(n)
void printSubstrings2(string s)
{
  int n = s.length();
  for(int i=0; i<n; i++)
  {
    string subStr="";           //initialising substring starting from index i
    for(int j = i; j < n; j++)    
    {
      subStr+=s[j];             //progressively adding character to the substring to get new substring 
      cout<<subStr<<endl;       //printing the new substring
    }
  }
}

//Driver Code
int main()
{
  string s;
  cin>>s;
  printSubstrings(s);
  cout<<endl;
  printSubstrings2(s);
}