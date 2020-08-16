#include <bits/stdc++.h>
#include <vector>

using namespace std;

int shiftArr(vector<int> &nums, int len)
{
    int pos = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] <= 0 && i != pos)
        {
            int temp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = temp;
            pos++;
        }
    }
    return pos;
}
int solve(vector<int> &nums, int len, int shift)
{
    for (int i = shift; i < len; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    int newLen = len - shift;
    for (int i = shift; i < len; i++)
    {
        int newPos = i - shift;

        if (abs(nums[i]) - 1 > 0 && abs(nums[i]) - 1 < newLen)
        {
            cout << "val " << abs(nums[i]) << "\n";
            int targetPos = nums[i] + shift - 1;
            cout << "tp " << targetPos << "\n";
            nums[targetPos] = -nums[targetPos];
        }
    }
    for (int i = shift; i < len; i++)
    {
        if (nums[i] > 0)
        {
            cout << "ret " << nums[i] << i << "\n";
            return i - shift + 1;
        }
    }
    return len - shift + 1;
}
int firstMissingPositive(vector<int> &nums)
{
    int len = nums.size();
    int shiftPos = shiftArr(nums, len);
    cout << "sp " << shiftPos << "\n";
    int res = solve(nums, len, shiftPos);
    return res;
}
int main()
{
    vector<int> vi = {1, 2, 0};
    int res = firstMissingPositive(vi);
    cout << "final res " << res;
}