#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int> &nums)
{
    int pos1, pos2;
    int i, j;
    int n = nums.size();
    for (int i = 0, j = n - 1; i < j; j--)
    {
        while (i < j && i < n && nums[i] == 0)
        {
            i++;
        }
        while (j > i && j >= 0 && nums[j] == 2)
        {
            j--;
        }
        if (i < j && (nums[i] == 2 || nums[j] == 0))
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
}

int main()
{
    vector<int> a = {2, 0, 2, 1, 1, 0};
    sortColors(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}