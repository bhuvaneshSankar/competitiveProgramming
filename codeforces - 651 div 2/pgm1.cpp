#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator
#define nl "\n"

using namespace std;

bool isEven(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    return false;
}
int greatestOddDivisor(int val)
{
    while (isEven(val))
    {
        val = val / 2;
    }
    return val;
}
void solve()
{
    int n;
    cin >> n;
    long long int turn = 1; // 1 for ashishgup 2 for fastfinger
    bool flag = true;
    while (flag == true)
    {
        if (n == 1)
        {
            turn++;
            flag = false;
            break;
        }
        else if (n % 2 != 0)
        { //if it is odd
            flag = false;
            break;
        }
        else
        { //even - get greatest odd divisor
            int go = greatestOddDivisor(n);
            if (go != 1)
            { // go must be greater than one
                n = n / go;
                turn++;
            }
            else
            { //go equals 1 so subtract the n by one
                n -= 1;
                turn++;
            }
        }
    }
    if (!isEven(turn))
    {
        cout << "Ashishgup" << nl;
    }
    else
    {
        cout << "FastestFinger" << nl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}
