#include<iostream>
#include<cstring>     //memset()
using namespace std;


/****************Checking whether a given number is prime******************/

//1st Method(Naive Approach)
//Checking whether any number 2 to n-1 divides the given n
bool isPrime1(int n)
{
  //corner case
  if(n<=1)
    return false;

  for(int i=2;i<=n-1;i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}

//2nd Method
//Checking whether any number 2 to (sqrt(n)) divides the given n
bool isPrime2(int n)
{
  //corner case
  if(n<=1)
    return false;

  for(int i=2; i*i<=n; i++)
    if(n%i==0)
      return false;
  return true;
}
//Url:(//https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-the-number-is)


//3rd Method
//Optimising the second method based on the fact that all primes greater than 3
//are of the form 6k±1 ∀ k>0
//we will be dividing the number only by the supposed prime numbers
bool isPrime3(int n)
{
  if(n==2 || n==3)
    return true;
  if(n<=1 || n%2 == 0 || n%3 == 0)
    return false;
  
  for(int i=5; i*i<=n; i+=6)
  {
    if(n%i == 0 || n%(i+2) == 0)
      return false;
  }
  return true;
}


/***********************Sieve Of Eratosthenes***************************/

//Simple Sieve(Printing primes from 2 to n)
void simpleSieve(int n)
{
  //boolean array to mark whether numbers from 1 to n are prime or not
  bool isPrime[n+1];
  //initially mark all numbers as prime
  memset(isPrime,true,sizeof(isPrime));

  for(int i=2; i*i<=n; i++)   //traversing till square root to avoid repetition
  {
    if(isPrime[i])  //if number is prime
    {
      for(int j=i*i;j<=n;j+=i)  //starting with i*i to avoid repetition of previously marked numbers
        isPrime[j] = false;     //mark the multiples of prime false
    }
  }
  
  //printing the primes
  for(int i=2;i<=n;i++)
    if(isPrime[i])
      cout<<i<<" ";
  cout<<"\n";
}

//Segmented Sieve

int main()
{
  simpleSieve(100);
}