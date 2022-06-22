#include<iostream>
#include<map>
#include<set>
#include<cstring>      //memset()
using namespace std;
typedef int64_t lli;

void printAllFactors(int n)
{
  set<int> factors;
  for(int i=1; i*i<=n; i++) //traversing till sqrt(n) to avoid repeating the divisors
  {
    if(n%i == 0)
    {
      factors.insert(i);
      factors.insert(n/i);  //in case i and n/i are equal, the set will reject n/i, thus no duplicate values
    }
  }
  cout<<"number of factors: "<<factors.size()<<endl;
  for(auto factor:factors)
    cout<<factor<<" ";
  cout<<endl;
}

void printPrimeFactors(int n)
{
  if(n<=1)
    return;
  map<int,int> factors; 
  while(n%2==0)
  {
    factors[2]+=1;
    n/=2;
  }

  for(int i=3; i*i<=n; i+=2)
  {
    while(n%i==0)
    {
      factors[i]+=1;
      n/=i;
    }
  }

  if(n>1) //if n(original value) or n(after reduction) is prime 
  {
    factors[n]=1;
  }
  cout<<"\nThere are "<<factors.size()<<" prime factor(s) of given number"<<endl;
  for(auto factor:factors)
  {
    cout<<factor.first<<" raised to power "<<factor.second<<endl;
  }
}



int main()
{
  int n; cin>>n;  //say 110
  printAllFactors(n);
  printPrimeFactors(n);
}