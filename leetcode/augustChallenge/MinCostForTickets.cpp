#include <bits/stdc++.h>
#include <vector>
using namespace std;
int gmin = INT_MAX;

void minCost(vector<int> days, vector<int> costs, int pos, int valid, int tc)
{
    if (pos >= days.size() || valid > days[days.size() - 1] + 1)
    {
        gmin = min(gmin, tc);
        return;
    }
    if (tc < gmin)
    {
        if (pos < days.size() && (pos == 0 || valid <= days[pos]))
        {
            //   cout<<" here\n";
            minCost(days, costs, pos + 1, days[pos] + 1, tc + costs[0]);
            minCost(days, costs, pos + 1, days[pos] + 7, tc + costs[1]);
            minCost(days, costs, pos + 1, days[pos] + 30, tc + costs[2]);
        }
        else if (valid > days[pos])
        {
            //  cout<<" here2\n";
            minCost(days, costs, pos + 1, valid, tc);
        }
    }
}
/**
     * generate all possibilities o(3^n)
     */
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    gmin = INT_MAX;
    minCost(days, costs, 0, days[0], 0);
    int lmin = gmin;
    gmin = INT_MAX;
    return lmin;
}
int min(int a, int b, int c)
{
    return a < b && a < c ? a : b < c ? b : c;
}
/**
     * dp approach o(nlogn)
     */
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = min(costs[0], costs[1], costs[2]);
    for (int i = n - 2; i >= 0; --i)
    {
        int c1, c2, c3;
        c1 = costs[0] + dp[i + 1];
        auto it1 = lower_bound(days.begin(), days.end(), days[i] + 7);
        int pos;
        if (it1 == days.end())
        {
            c2 = costs[1];
        }
        else
        {
            pos = it1 - days.begin();
            c2 = costs[1] + dp[pos];
        }
        auto it2 = lower_bound(days.begin(), days.end(), days[i] + 30);
        if (it2 == days.end())
        {
            c3 = costs[2];
        }
        else
        {
            pos = it2 - days.begin();
            c3 = costs[2] + dp[pos];
        }
        dp[i] = min(c1, c2, c3);
    }
    return dp[0];
}
int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    mincostTickets(days, costs);
}