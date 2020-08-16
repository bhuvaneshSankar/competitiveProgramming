#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator

using namespace std;

int max(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    int l1 = s.length();
    int l2 = t.length();
    char s1[l1 + 1];
    char s2[l2 + 1];
    strcpy(s1, s.c_str());
    strcpy(s2, t.c_str());
    int dp[l1 + 1][l2 + 1];
    foi(i, l1 + 1)
    {
        dp[i][0] = 0;
    }
    foj(j, l2 + 1)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    if (dp[l1][l2] == s.length())
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
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