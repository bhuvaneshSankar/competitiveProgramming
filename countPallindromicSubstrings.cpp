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

int p = 1e9 + 9;
int getCount(char s[], int len, int pallLen)
{
    int h = 0;
    for (int i = 0; i < pallLen; i++)
    {
        int exp = pallLen - i - 1;
        h += ((s[i] - 'a' + 1) * (int)(pow(26, exp))) % p;
    }
    int ha[len];
    ha[0] = h;
    int i;
    for (i = 1; i <= len - pallLen; i++)
    {
        int exp = pallLen - 1;
        int prev = ((s[i - 1] - 'a' + 1) * ((int)(pow(26, exp)))) % p;
        int pos = i + pallLen - 1;
        ha[i] = (ha[i - 1] - prev) * 26 + (s[pos] - 'a' + 1);
    }
    while (i < len)
    {
        ha[i] = -1;
        i++;
    }
    int prevSize = len - pallLen + 1;
    int prev[len];
    int k = 0;
    h = 0;
    for (i = len - 1; k < pallLen; k++, i--)
    {
        int exp = pallLen - k - 1;
        h += ((s[i] - 'a' + 1) * (int)(pow(26, exp))) % p;
    }
    prev[len - 1] = h;
    for (i = len - 2, k = prevSize - 2; i >= pallLen - 1; i--, k--)
    {
        int exp = pallLen - 1;
        int prevVal = ((s[i + 1] - 'a' + 1) * ((int)(pow(26, exp)))) % p;
        int pos = i - pallLen + 1;
        prev[i] = (prev[i + 1] - prevVal) * 26 + (s[pos] - 'a' + 1);
    }
    while (i >= 0)
    {
        prev[i] = -1;
        --i;
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        int t = i + pallLen - 1;
        if (ha[i] != -1 && ha[i] == prev[t])
        {
            count++;
        }
    }
    return count;
}

void solve()
{
    int len;
    cin >> len;
    char s[len];
    cin >> s;
    int val = 0;
    for (int i = 2; i <= len; i++)
    {
        //    cout << "i = " << i << nl;
        int res = getCount(s, len, i);
        //    cout << "res " << res << nl;
        val += res;
    }
    cout << val << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}