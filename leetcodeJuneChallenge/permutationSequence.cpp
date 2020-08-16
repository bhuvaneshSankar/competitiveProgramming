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
void solve()
{
    int n, k;
    cin >> n >> k;
    set<string> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(to_string(i));
    }
    string ans = "";
    vector<ll> fact(n);
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
        fact[i - 1] = f;
    }
    for (int i = 0; i < fact.size(); i++)
    {
        cout << fact[i] << " ";
    }
    cout << nl;
    for (string str : s)
    {
        cout << str << " ";
    }
    cout << nl;

    cout << nl;
    while (s.empty() == false || n > 0)
    {
        if (n == 1)
        {
            set<string>::iterator itr = s.begin();
            ans += *itr;
            break;
        }
        f = fact[n - 1];
        int bs = f / n;
        int tgb = k / bs;
        int rem = k % bs;
        if (k % bs != 0)
        {
            tgb++;
        }
        cout << "tgb " << tgb << nl;
        set<string>::iterator itr = s.begin();
        if (rem == 0 && bs == 1)
        {
            //cout << "tgb " << tgb << " " << *itr << nl;
            std::advance(itr, tgb);
        }
        else
        {
            std::advance(itr, tgb - 1);
        }
        string str = *itr;
        s.erase(itr);
        ans += str;
        n--;
        //  k = tgb + (k % bs);
        if (rem != 0)
        {
            k = rem;
        }
        else if (rem == 0)
        {
            k = k - tgb;
        }
        // if (k == 0)
        // {
        //     while (s.empty() == false)
        //     {
        //         set<string>::iterator itr = s.begin();
        //         string str = *itr;
        //         ans += str;
        //         s.erase(itr);
        //     }
        // }
    }
    cout << "ans " << ans << nl;
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