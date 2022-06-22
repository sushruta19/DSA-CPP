#include<iostream>
#include<map>
#include<set>
#include<cstring>      //memset()
using namespace std;
typedef int64_t lli;


//function to print three distinct divisors a,b,c of n such that a!=b!=c!=1
void print3DistinctDivisor(lli n)
{
  //prime numbers can't be represented in a*b*c form
  if(n<=2)
  {
    cout<<"NO\n";
    return;
  }
  lli a=1,b=1,c=1;
  //finding the smallest divisor a
  for(int i=2; i*i<=n; i++)
  {
    if(n%i == 0)
    {
      a = i;
      n/=i;       //now we have n = n/a = b*c
      break;
    }
  }
  //finding the smallest divisor b of n = n/a = b*c
  for(lli i=2; i*i<=n; i++)
  {
    if(n%i == 0)
    {
      if(i!=a)      //if the smallest divisor b of n=n/a=b*c is not equal to 'a' which is the given condition
      {
        b = i;      //put b equal to the smallest divisor we found which is not equal to a
        c = n/i;    //c automatically will be n/ab
        break;
      }
    }
  }
  if(a!=b && b!=c &&c!=1) //checking the given conditions
  {
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c<<endl;
  }
  else cout<<"NO\n"; 
}