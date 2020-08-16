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
int tc = 1;
ll mx = 1e9 + 7;
ll getCount(vi ar, int s, int n, ll cnt, int flag)
{
    for (int i = s + 1; i < n; i++)
    {
        if (ar[i] == ar[i - 1])
        {
            continue;
        }
        else if (ar[i] < ar[i - 1])
        {
            flag--;
        }
        else if (ar[i] > ar[i - 1])
        {
            flag++;
        }
        if (flag < 1 || flag > 4)
        {
            ll lc = 1e9 + 7;
            for (int j = 1; j < 5; j++)
            {
                ll val = getCount(ar, i, n, cnt + 1, j);
                if (val < lc)
                {
                    lc = val;
                }
            }
            return lc;
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    vi ar(n);
    foi(i, n)
    {
        cin >> ar[i];
    }
    ll mx = 1e9 + 7;
    for (int i = 1; i < 5; i++)
    {
        ll count = getCount(ar, 0, n, 0, i);
        if (count < mx)
            mx = count;
    }
    cout << "Case #" << (tc) << ": " << mx << "\n";
    tc++;
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