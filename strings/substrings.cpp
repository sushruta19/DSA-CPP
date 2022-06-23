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

//function to check whether arg1 is a substring of arg2
bool isSubstring(string sub, string s)
{
  int counter = 0;
  for(int i=0;i<s.length();i++)
  {
    if(counter == sub.length())
      break;
    if(sub[counter] == s[i])
      counter++;
    else
      counter = 0;
  }
  if(counter == sub.length())
    return true;
  return false;
}

//function to check whether arg1 is a subsequence of arg2
//subsequence means whether the order is correct or not
bool isSubsequence(string sub, string s)
{
  int counter =0;
  for(int i=0; i<s.length();i++)
  {
    if(counter == sub.length())
      break;
    if(sub[counter] == s[i])
      counter++;
  }
  if(counter == sub.length())
    return true;
  return false;
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