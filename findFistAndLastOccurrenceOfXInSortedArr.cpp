#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*took 16ms to pass leetcode tcs*/
vector<int> searchRange(vector<int> &nums, int target) //o(n + log(n))
{
    vector<int> range(2, -1);
    int endingIndex = upper_bound(nums.begin(), nums.end(), target) - nums.begin(); //logn
    cout << "ending index " << endingIndex << "\n";
    if (endingIndex == 0 || nums[endingIndex - 1] != target)
    {
        return range;
    }
    else
    {
        endingIndex--;
        range[1] = endingIndex;
        while (endingIndex >= 0 && nums[endingIndex] == target) //o(n) at worst case if all the elements in array are same
        {
            endingIndex--;
        }
        range[0] = endingIndex + 1;
        return range;
    }
}
/*took 12 ms to pass leetcode tc's*/
vector<int> searchRangeOptimized(vector<int> &nums, int target)
{
    vector<int> range(2, -1);
    int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int end = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
    if (start < end)
    {
        range[0] = start;
        range[1] = end - 1;
    }
    return range;
}
int binarySearch(vector<int> &a, int target, int start, int end) //o(logn)
{
    int pos = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (a[mid] >= target)
        {
            pos = mid;
            end = mid - 1;
            //    return binarySearch(a, target, start, mid - 1);
        }
        else
        {
            start = mid + 1;
            //    return binarySearch(a, target, mid + 1, end);
        }
    }

    return pos;
}
vector<int> searchRangeUsingBinarySearchImpl(vector<int> &a, int target)
{
    vector<int> range(2, -1);
    int n = a.size();
    int start = binarySearch(a, target, 0, n - 1);
    if (start == -1)
    {
        return range;
    }
    int end = binarySearch(a, target + 1, 0, n - 1);
    if (end == -1)
    {
        end = n;
    }
    range[0] = start;
    range[1] = end - 1;
    return range;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target = 8;
    vector<int> range = searchRangeUsingBinarySearchImpl(v, target);
    cout << "\n";
    for (int a : range)
    {
        cout << a << " ";
    }
}