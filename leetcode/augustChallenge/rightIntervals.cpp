/**
 * Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
 

Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
 

Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
 

Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
 * /
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    set<pair<int, int>> st;
    for (int i = 0; i < intervals.size(); ++i)
    {
        st.insert({intervals[i][0], i});
    }
    vector<int> res;
    for (pair<int, int> pr : st)
    {
        cout << pr.first << " " << pr.second << "\n";
    }
    for (int i = 0; i < intervals.size(); ++i)
    {
        vector<int> v = intervals[i];
        int target = v[1];
        auto it = std::find_if(st.begin(), st.end(), [target](const pair<int, int> &p) { return p.first >= target; });
        if (it == st.end())
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(it->second);
        }
    }
    return res;
}
//optimized
int binarySearch(vector<pair<pair<int, int>, int>> &intervals, int tg)
{
    int n = intervals.size();
    int l = 0, r = n - 1;
    if (intervals[n - 1].first.first < tg)
        return -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (intervals[mid].first.first >= tg)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return intervals[l].second;
}
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    vector<pair<pair<int, int>, int>> sortedIntervals;
    int n = intervals.size();
    for (int i = 0; i < n; ++i)
    {
        sortedIntervals.push_back({{intervals[i][0], intervals[i][1]}, i});
    }
    sort(sortedIntervals.begin(), sortedIntervals.end());
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i)
    {
        res[i] = binarySearch(sortedIntervals, intervals[i][1]);
    }
    return res;
}