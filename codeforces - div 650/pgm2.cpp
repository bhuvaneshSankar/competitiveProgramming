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

#define max 100;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    foi(i, n)
    {
        cin >> arr[i];
    }
    int oc = 0, ec = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i] % 2 != 0)
        {
            oc++;
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] % 2 == 0)
        {
            ec++;
        }
    }
    if (oc != ec)
    {
        cout << "-1" << nl;
    }
    if (oc == ec)
    {
        cout << oc << nl;
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