#include<iostream>
#include<cstring>     //memset()
using namespace std;

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