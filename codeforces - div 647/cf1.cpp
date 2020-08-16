//Johnny and ancient computing

#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;
int minCount = INT_MAX;

int solve(ll a, ll b)
{
    int count = 0;
    if (a == b)
    {
        return count;
    }
    while (a > b)
    {
        if (a / 8 >= b && a % 8 == 0)
        {
            a = a / 8;
            count++;
        }
        else if (a / 4 >= b && a % 4 == 0)
        {
            a = a / 4;
            count++;
        }
        else if (a / 2 >= b && a % 2 == 0)
        {
            a = a / 2;
            count++;
        }
        else
        {
            break;
        }
    }
    if (a == b)
    {
        return count;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
        {
            ll temp = a;
            a = b;
            b = temp;
        }
        cout << solve(a, b) << endl;
    }
}