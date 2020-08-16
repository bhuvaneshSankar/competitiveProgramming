#include <bits/stdc++.h>
#include <math.h>
using namespace std;
/**
 * check whether a given number is power of four
 * approach :
 * condition 1: there must be only one set bit in the number
 * how to : find the set bit position and then 1<<(pos-1) must yield the same number 
 * condition 2: position of the set bit must be odd
 * how to : find the set bit position and then check for odd
 * right most set bit position
 * how to : log2(number)
 * tc = o(log(32)) since log2 function takes logn time
*/
bool isPowerOfFour(int num)
{
    if (num <= 0)
        return false;
    int rightMostSetBitPos = log2(num) + 1;
    if ((num == 1 << (rightMostSetBitPos - 1)) && ((rightMostSetBitPos & 1) == 1))
    {
        return true;
    }
    return false;
}

/**
 * condition 1: number is greater than zero
 * condition 2: it must be power of 2
 * how to : number & number-1 is zero
 * condition 3: power of 4 has set bit in the odd position only
 * how to : number & 0xaaaaaaaa is zero
 * tc = o(1)
*/
bool isPowerOfFour(int num)
{
    if (num > 0 && ((num & (num - 1)) == 0) && ((num & 0xaaaaaaaa) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
