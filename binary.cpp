#include <iostream>
using namespace std;

int main()
{
    int x = 121;
    // for (int i = 10; i >= 0; i--)
    // {
    //     if ((x & 1 << i) != 0)
    //     {
    //         cout << 1;
    //     }
    //     else
    //     {
    //         cout << 0;
    //     }
    // }
    cout << "number of 1's in the binary representation of the given number\n"
         << __builtin_popcount(x);
}