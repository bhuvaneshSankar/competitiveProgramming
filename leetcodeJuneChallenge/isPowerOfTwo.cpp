#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 1)
    {
        cout << "no";
    }
    double flag = log(n) / log(2);

    cout << (log2(n)) << "  " << ceil(log2(n)) << " " << floor(log2(n)) << "\n";
    //0ms to pass
    if (ceil(log2(n)) == floor(log2(n)))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    //4ms to pass
    cout << __builtin_popcount(n) << "\n";
}