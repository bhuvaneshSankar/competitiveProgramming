#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator

using namespace std;

//wrong logic
// int coinChangeCount(vi &v, int n, int target)
// {
//     int prefixSum = 0;
//     int count = 0;
//     foi(i, n)
//     {
//         int val = v[i];
//         prefixSum += val;
//         deb2(i, prefixSum);
//         if (val == target)
//         {
//             cout << "case 1 - " << val << "\n";
//             count++;
//         }
//         else if (prefixSum == target)
//         {
//             cout << "case 2 - " << prefixSum << "\n";
//             count++;
//         }
//         int offset = target - prefixSum;
//         if (offset > 0 && offset < target)
//         {
//             foj(j, i + 1)
//             {
//                 if (offset % v[j] == 0)
//                 {
//                     cout << "case 3 \n";
//                     deb2(offset, j);
//                     count++;
//                 }
//             }
//         }
//     }
//     return count;
// }
//16 ms
int coinChangeCountOpt(vi v, int n, int target)
{
    int dp[n + 1][target + 1];
    for (int i = 1; i <= target; i++)
    {
        dp[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = 1;
    }
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= target; j++)
        {
            if (j >= v[i - 1])
            {
                dp[i][j] = dp[i][j - v[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    foi(i, n) cin >> v[i];
    int target;
    cin >> target;
    int count = coinChangeCountOpt(v, n, target);
    deb(count);
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

//1 2 5 - target - 5 => 4
//10 -target - 10 => 1
//3 - target -2 => 0