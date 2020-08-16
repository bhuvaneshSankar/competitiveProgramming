#include <bits/stdc++.h>
using namespace std;
int hIndex(vector<int> &citations)
{
    int len = citations.size();
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (citations[mid] == len - mid)
        {
            return citations[mid];
        }
        else if (citations[mid] > (len - mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return len - low;
}