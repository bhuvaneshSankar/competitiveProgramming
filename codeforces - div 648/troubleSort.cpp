#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
#define vi vector<int>
#define si set<int>
#define itriv vector<int>::iterator
#define itris set<int>::iterator
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, m) for (int j = 0; j < m; j++)
#define deb(val) cout << #val << " - " << val << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int type[n];
    foi(i, n) cin >> arr[i];
    foi(i, n) cin >> type[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1] && type[j] != type[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = type[j];
                type[j] = type[j + 1];
                type[j + 1] = temp;
            }
            else if (arr[j] > arr[j + 1] && type[j] == type[j + 1])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
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
        t--;
        solve();
    }
}