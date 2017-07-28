#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, test;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%d", &n);
        int temp = (-1) * n;
        int low = n & temp;
        int left = n + low;
        int change = n ^ left;
        int right = (change/low)>>2;
        printf("Case %d: %d\n",caseno, left|right);
    }
    return 0;
}

/*
 * Returns the next higher integer with the same number of one bits. The
 * parameter is:
 *
 * value - the value on which to perform the calculation
function hakmemItem175(value){

  // find the lowest one bit in the input
  var lowestBit = value & -value;

  // determine the leftmost bits of the output
  var leftBits = value + lowestBit;

  // determine the difference between the input and leftmost output bits
  var changedBits = value ^ leftBits;

  // determine the rightmost bits of the output
  var rightBits = (changedBits / lowestBit) >>> 2;

  // return the complete output
  return (leftBits | rightBits);

}*/
