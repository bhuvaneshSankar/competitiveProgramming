#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
int nthUglyNumber(int n)
{
    int n2, n3, n5;
    n2 = -1;
    n3 = -1;
    n5 = -1;
    int i2, i3, i5;
    i2 = 2;
    i3 = 3;
    i5 = 5;
    vector<int> v(1695);
    v[0] = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        res = min(i2, i3, i5);
        if (res == i2)
        {
            n2++;
            v[i] = 2 * v[n2];
            i2 = v[i];
        }
        else if (res == i3)
        {
            n3++;
            v[i] = 3 * v[n3];
            i3 = v[i];
        }
        else if (res == i5)
        {
            n5++;
            v[i] = 5 * v[n5];
            i5 = v[i];
        }
        cout << i << " " << v[i] << " " << n2 << " " << n3 << " " << n5 << "\n";
    }

    // int res = min(n2, n3, n5);
    // cout << res << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    return res;
}

int main()
{
    int res = nthUglyNumber(5);
    cout << "res " << res;
}

unsigned getNthUglyNo(unsigned n)
{
    unsigned ugly[n]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
        cout << i << " " << ugly[i] << " " << next_multiple_of_2 << " " << next_multiple_of_3 << " " << next_multiple_of_5 << "\n";
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
