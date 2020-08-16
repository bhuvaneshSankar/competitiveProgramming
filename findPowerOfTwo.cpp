#include <bits/stdc++.h>

using namespace std;

int calculateSizeOfArray(int n)
{
    if (__builtin_popcount(n) == 1)
    { //power of 2
        return n;
    }
    else
    {
        for (int i = 0;; i++)
        {
            if ((1 << i) > n)
            {
                return 1 << i;
            }
        }
    }
}

int main()
{
    cout << calculateSizeOfArray(7);
}