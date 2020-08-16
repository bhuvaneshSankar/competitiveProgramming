#include <bits/stdc++.h>
#include <vector>
using namespace std;
void binarySearch(vector<int> citations, int start, int end, int &h)
{
    while (start <= end)
    {
        int mid = (end + start) / 2;
        auto it = lower_bound(citations.begin(), citations.end(), mid);
        int dist = distance(citations.begin(), it);
        int right = citations.size() - dist;
        if (right >= (mid))
        {
            h = (mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}
int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int h = 0;
    if (citations.size() == 0)
    {
        return h;
    }
    binarySearch(citations, 0, citations[citations.size() - 1], h);
    return h;
}