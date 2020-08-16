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

bool isEqual(vector<int> a, vector<int> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
vector<int> prisonAfterNDays(vector<int> &cells, int N)
{
    N = N % 14;
    cout << N;

    for (int i = 0; i < N; i++)
    {
        vector<int> copy = cells;
        for (int j = 0; j < cells.size(); j++)
        {
            if (j == 0 || j == cells.size() - 1)
            {
                copy[j] = 0;
            }
            else
            {
                if (cells[j - 1] == cells[j + 1])
                {
                    copy[j] = 1;
                }
                else
                {
                    copy[j] = 0;
                }
            }
        }
        for (int i = 0; i < copy.size(); i++)
        {
            cout << copy[i] << " ";
        }
        cout << "\n";
        cells = copy;
    }
    return cells;
}
void solve()
{
    vector<int> a = {1, 0, 0, 1, 0, 0, 0, 1};
    prisonAfterNDays(a, 826);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}