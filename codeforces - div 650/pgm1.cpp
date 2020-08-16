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
    char str[1000];
    char s[1000];
    cin >> str;
    int len = strlen(str);
    cout << "len " << strlen(str);
    s[0] = str[0];
    s[1] = str[1];
    int k = 2;
    for (int i = 3, k = 2; i < len; i += 2)
    {
        s[k] = str[i];
        k++;
        cout << k << nl;
    }
    s[k] = '\0';
    cout << "k = " << k << nl;
    for (int i = 0; i < k; i++)
    {
        cout << s[i];
    }
    cout << nl;
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