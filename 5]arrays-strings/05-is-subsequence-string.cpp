#include<iostream>
#include<string>      //substr()
using namespace std;

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