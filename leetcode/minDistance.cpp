/**
 * min distance between largest and smallest element after three moves
 * one move -> convert a number to any another number
 **/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int minDifference(vector<int> &nums)
{
    if (nums.size() < 5)
        return 0;
    sort(nums.begin(), nums.end());
    int ans = 10e5 + 7;
    int i, j;
    for (i = 3, j = nums.size() - 1; ~i; --i, --j)
    {
        cout << "i = " << i;
        ans = min(nums[j] - nums[i], ans);
    }
    cout << "out " << i << "\n";
    return ans;
}

int main()
{
    vector<int> v = {1, 5, 0, 10, 14};
    int i;
    for (i = 20; ~i; --i)
    {
        cout << " i = " << i;
    }
    cout << " out " << i;
    int val = minDifference(v);
    cout << val;
}
