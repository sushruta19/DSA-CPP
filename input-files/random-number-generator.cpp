/*This program generates random numbers and prints in a text file in the same
 *directory where the program is located.
 *It creates a text file named "random-numbers.txt"
*/

#include<iostream>
using namespace std;

int main()
{
  srand(time(NULL));
  
  FILE* fp = fopen("./random-numbers.txt","w");
  if (fp == NULL)
  {
    cout<<"File couldn't be opened/created.\n";
    exit(1);
  }
  
  cout<<"Enter the number of random numbers: ";
  int n;
  cin>>n;
  cout<<"Set the range [a,b]\n";
  int a,b;
  cout<<"a = "; cin>>a;
  cout<<"b = "; cin>>b;
  while(n--)
  {
    int x = a + rand()%(b+1-a);
    fprintf(fp,"%d\n", x);
  }
  fclose(fp);
  cout<<"DONE!\n";
  return 0;
}