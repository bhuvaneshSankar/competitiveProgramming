#include <bits/stdc++.h>
#include <vector>
#include <set>
#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator
#define nl "\n"
int max = 2 * 1e5;
using namespace std;
//tle
void solve()
{
    int n, k;
    cin >> n >> k;
    char a[n];
    cin >> a;
    int len = strlen(a);
    set<int> zs, os;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '0')
        {
            zs.insert(i);
        }
        else if (a[i] == '1')
        {
            os.insert(i);
        }
    }
    int prev = -1;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '1')
        {
            prev = i;
        }
        else if (a[i] == '0')
        {
            auto it = upper_bound(os.begin(), os.end(), i);
            int nextOne = -1;
            if (it != os.end())
            {
                nextOne = *it;
            }
            if (prev == -1 && nextOne == -1)
            {
                count++;
                prev = i;
                zs.erase(i);
                os.insert(i);
            }
            else if (prev == -1)
            {
                if (i + k < nextOne)
                {
                    //valid to make this pos as 1
                    count++;
                    prev = i;
                    zs.erase(i);
                    os.insert(i);
                }
            }
            else if (nextOne == -1)
            {
                if (i - k > prev)
                {
                    count++;
                    prev = i;
                    zs.erase(i);
                    os.insert(i);
                }
            }
            else
            {
                if (i + k < nextOne && i - k > prev)
                {
                    //valid to make this pos as 1
                    count++;
                    prev = i;
                    zs.erase(i);
                    os.insert(i);
                }
            }
        }
    }
    cout << count << nl;
}
//accepted
void solve1()
{
    int n, k;
    cin >> n >> k;
    char a[n];
    cin >> a;
    int len = strlen(a);
    vector<int> os;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '1')
        {
            os.push_back(i);
        }
    }
    int count = 0;
    if (os.size() == 0)
    {
        count = 1 + ((len - 1) / (k + 1));
    }
    else if (os.size() == 1)
    {
        int diff = os[0] - (k + 1);
        if (diff >= 0)
        {
            int c = 1 + ((diff) / (k + 1));
            count += c;
        }
        diff = len - ((os[os.size() - 1] + k + 1));
        if (diff > 0)
        {
            int c = 1 + ((diff - 1) / (k + 1));
            count += c;
        }
    }
    else
    {

        for (int i = 0; i < os.size() - 1; i++)
        {
            if (i == 0)
            {
                int diff = os[i] - (k + 1);
                if (diff >= 0)
                {
                    int c = 1 + ((diff) / (k + 1));
                    count += c;
                    //    cout << "count = " << count << nl;
                }
            }
            int curr = os[i];
            int next = os[i + 1];
            int nv = os[i] + (k + 1);
            int pv = os[i + 1] - (k + 1);
            if (nv <= pv)
            {
                int permitted = pv - nv + 1;
                int c = 1 + ((permitted - 1) / (k + 1));
                count += c;
                //    cout << "i = " << i << " count = " << count << nl;
            }
        }
        int diff = len - ((os[os.size() - 1] + k + 1));
        if (diff > 0)
        {
            int c = 1 + ((diff - 1) / (k + 1));
            count += c;
        }
    }
    cout << count << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //   cin.tie(NULL);
    //   cout.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        solve1();
    }
}