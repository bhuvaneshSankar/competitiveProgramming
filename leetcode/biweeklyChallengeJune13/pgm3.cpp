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

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> res(prices.size());
        for (int i = 0; i < prices.size(); i++)
        {
            res[i] = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    res[i] = res[i] - prices[j];
                    break;
                }
            }
        }
        return res;
    }
};

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