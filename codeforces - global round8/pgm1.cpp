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

ll gc = INT_MAX;

void findd(ll a, ll b, ll n, ll cnt)
{
    if (cnt > 3)
    {
        if (a / 2 >= b || b / 2 >= a)
        {
            return;
        }
    }
    if (a > n || b > n)
    {
        if (cnt < gc)
        {
            gc = cnt;
        }
        return;
    }
    findd(a + b, b, n, cnt + 1);
    findd(a, b + a, n, cnt + 1);
}
void solve()
{
    ll a;
    ll b;
    ll n;
    cin >> a >> b >> n;
    findd(a, b, n, 0);
    cout << gc << nl;
    gc = INT_MAX;
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