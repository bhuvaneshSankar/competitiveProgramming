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
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int flag = 0;
    si ser, sec;
    int val;
    foi(i, n)
    {
        foj(j, m)
        {
            cin >> val;
            arr[i][j] = val;
            if (val == 1)
            {
                ser.insert(i);
                sec.insert(j);
            }
        }
    }

    int turn;
    for (turn = 0;; turn++)
    {
        int posx = 0, posy = 0;
        while (ser.find(posx) != ser.end())
        {
            posx++;
        }
        if (posx >= n)
        {
            break;
        }
        while (sec.find(posy) != sec.end())
        {
            posy++;
        }
        if (posy >= m)
        {
            break;
        }
        ser.insert(posx);
        sec.insert(posy);
    }
    if (turn % 2 == 0)
    {
        cout << "Vivek\n";
    }
    else
    {
        cout << "Ashish\n";
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
        t--;
        solve();
    }
}