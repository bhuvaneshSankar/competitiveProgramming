#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t a = 0;
    a = (n & 1) == 1 ? 1 : 0;
    for (int i = 1; i < 32; i++)
    {
        a = ((n & (1 << i)) != 0) ? (a << 1) + 1 : (a << 1);
    }
    return a;

    // n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);   //flip first 16 and next 16 bits
    // n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);       //flip by 8 bits
    // n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);       //flip by 4 bits
    // n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);       //flip by 2 bits
    // n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);       //flip by 1 bits
    // return n;
}