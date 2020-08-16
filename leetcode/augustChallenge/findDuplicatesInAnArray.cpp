#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
 * Array consists of elements between 1 to n
 * an element in an array occurs twice or once
 * return all the elements that has occurred twice in o(n) time and o(1) space
 */
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> duplicates;
    for (int i = 0; i < nums.size(); i++)
    {
        int targetIndex = nums[i];
        if (nums[i] < 0)
        {
            targetIndex = abs(nums[i]);
        }
        targetIndex--;
        if (nums[targetIndex] < 0)
        {
            duplicates.push_back(targetIndex + 1);
        }
        else
        {
            nums[targetIndex] = -nums[targetIndex];
        }
    }
    return duplicates;
}