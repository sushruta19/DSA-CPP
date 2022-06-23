#include<iostream>
using namespace std;

/*********************Check if number is palindrome*********************/

//reverse the number and check whether its equal to original one
//T:O(logn) or O(no. of digits) AS:O(1)
//Iterative
bool isPalindromeIterative(int n)
{
  int temp = n;
  int reverse=0;
  while(temp > 0)
  {
    reverse=10*reverse+temp%10;
    temp/=10;
  }
  if(reverse == n)
    return true;
  return false;
}

//reverse the number and check whether its equal to original one
//T:O(logn) or O(no. of digits) AS:O(1)
//Recursive
int getReverse(int n, int temp)
{
  if(n==0)
    return temp;
  temp = 10*temp + n%10;
  return getReverse(n/10,temp);
}
bool isPalindrome(int n)
{
  return getReverse(n,0) == n;
}

//if number is too big, take the input as a string
//iterative
bool isPalindrome2Iterative(string n)
{
  int low = 0;
  int high = n.length()-1;
  while(low<high)
  {
    if(n[low]!=n[high])
      return false;
    low++; high--;
  }
  return true;
}

//if number is too big, take the input as a string
//recursive
bool isPalindrome2(string n)
{
  return isPalindrome2Util(n,0,n.length()-1);
}

bool isPalindrome2Util(string n, int low, int high)
{
  if(high-low <= 0)
    return true;
  if(n[low] == n[high])
    return isPalindrome2Util(n,low+1, high-1);
  return false;
}







