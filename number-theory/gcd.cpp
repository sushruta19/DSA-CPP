#include<iostream>
#include<algorithm>
using namespace std;

//gcd of two numbers
int gcd(int a, int b)
{
  if(a==0)
    return b;
  else if(b==0)
    return a;
  else if(a>b)
    return gcd(a-b,b);
  return gcd(a,b-a);
}

//basic Euclidean algo to find GCD
int gcdEuclid(int a, int b)
{
  if(a==0)return b;
  if(b==0)return a;
  if(a>b)return gcdEuclid(a%b,b);
  return gcdEuclid(a,b%a);
}

//Short version of Basic Euclid Algo to find GCD
int gcdEuclid(int a, int b)
{
  if(b==0)
    return a;
  return gcdEuclid(b,a%b);
}

//GCD of more than 2 numbers
//T: O(nlogn) where n is largest element of array, AS:O(1)
//Iterative
int findGcd(int arr[], int n)
{
  int result = arr[0];
  for(int i=1; i<n;i++)
  {
    result = gcd(arr[i],result);
    if(result == 1)
      break;
  }
  return result;
}
