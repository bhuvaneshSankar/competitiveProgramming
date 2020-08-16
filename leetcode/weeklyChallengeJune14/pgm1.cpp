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
int findLeastNumOfUniqueInts(vector<int> &a, int k)
{
    map<ll, ll> m;
    multimap<ll, ll> rm;
    for (int i = 0; i < a.size(); i++)
    {
        int val = m[a[i]];
        val += 1;
        m[a[i]] = val;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        rm.insert(make_pair(it->second, it->first));
    }
    int flag = k;
    int i = 0;
    int res;
    for (auto it = rm.begin(); it != rm.end(); it++)
    {
        i++;
        int count = it->first;
        if (flag > count)
        {
            flag -= count;
        }
        else if (flag == count)
        {
            flag -= count;
            res = rm.size() - i;
            break;
        }
        else
        {
            res = rm.size() - i + 1;
            break;
        }
    }
    return res;
}
void solve()
{
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