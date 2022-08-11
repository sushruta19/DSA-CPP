#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int l, int r) {
  while(l<r) {
    swap(arr[l], arr[r]);
  }
}

//T:2n or O(n) AS:O(1)
void reversalRotate(int arr[], int n, int shift) {
  shift = shift%n;
  reverse(arr,0,shift-1);
  reverse(arr,shift, n-1);
  reverse(arr,0,n-1);
}

//T:O(n) AS:O(1)
void jugglingRotate(int arr[], int n, int shift) {
  shift = shift%n;
  for(int i=0; i<__gcd(shift,n); i++) {
    int j = i;
    int temp = arr[i];
    while(1) {
      int index = (j+shift)%n;

      if(index == i) {
        arr[j] = temp;
        break;
      }
      arr[j] = arr[index];
      j = index;
    }
  }  
}

void print(int arr[], int n) {
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int arr[] = {1,2,3,4,5,6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int shift;
  cin>>shift;
  jugglingRotate(arr,n, shift);
  print(arr,n);
}

/*Explanation :-
> How does the GCD decide the number of cycles needed to rotate the
> array?

let's find out why outer loop's length should be `GCD(n,k)` where n is the 
length of array and k is the shift. Let us assume length of outer loop should be `x`

In the juggling method of array rotation, inside the inner loop we basically swap the value of an array element `j` with 
value of another array element `(j+k) mod n` 

    arr[j] = arr[ (j+k) % n ]

so let's say for outer loop index `i=0` we will have possible values
for j as `0`, `(0+d) mod n`, `(0+2d) mod n`, `(0+3d) mod n`..... `(0+m*d) mod n
where m is the smallest integer where `(0+m*d) mod n` becomes equal to i (as it's cyclic).

now the inner loop terminates when `j`'s value becomes equal to `i`
therefore,   

     (0+m*d) mod n = i
     m*d mod n = 0

therefore `m*d` is the smallest number divisible by n and d both and by [definition][1] smallest number divisible by two
numbers is called as LCM of those two numbers.
so `m*d = LCM(n, d)`. this is just one inner loop. so one inner loop runs about `LCM(n, d)` length 
(beware this is not runtime of inner loop but only the length it covers).
so elements rotated by one loop will be `LCM(n,d)/d`  as we are using `d` to jump to next index.

so,
one loop covers `LCM(n,d)/d`
Outer loops will run for x times and will cover all n elements of array therefore,

     x * LCM(n,d) / d  = n

we can simplify above equation and re-write it as below

     x = (n*d)  / LCM(n,d)

which is GCD(n,d). i.e. GCD can be calculated by dividing product of two numbers with their LCM.

     x = GCD(n,d).


> Why is it that once we finish a cycle, we start the new cycle from the
> next element ie. can't the next element be already a part of a
> processed cycle?

You might have already observed that since we are jumping `k` units as a time in the inner loop once 
inner loop completes the first run length (`LCM(n,d)`) it's only going to repeat on the same indexes
and not on different indexes. so the indexes which were not covered in the first run due to a certain 
starting position `i` will not be touched unless you change the `i`. (that's why outer loop changes the `i`).
for e.g.  Let's take an array `A = [1,2,3,4,5,6]` where `n=6` and let's take `d=2`.

so if we trace the index `j` of inner loop for `i=0` it will be
`j => 0, 2, 4, 0`
and for `i=1` it will be `j = 1, 3, 5, 1`

in this example `GCD(6,2)` was 2.

if we would have picked an array of length 5 and `d=2` then the trace would have been `j => 0, 2, 4, 1, 3, 0` and there
would have only been one outer loop which also meets with `GCD(5,2)`= 1.
*/
