#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> um;
    for (int i = 2; i < nums.size(); i++)
    {
        um[nums[i]] += 1;
    }
    set<vector<int>> ans;
    int len = nums.size();
    for (int i = 0; i < len - 2; i++)
    {
        int initial = nums[i];
        int diff = -initial;
        vector<int> sol;
        bool found = false;
        if (i > 1)
            um[nums[i]] -= 1;
        for (int j = i + 1; j < len - 1; j++)
        {
            int ld = diff - nums[j];
            // if (um[ld] == 1 && ld == nums[j] && j == 1)
            // {
            //     continue;
            // }
            if (um[ld] > 0)
            {
                found = true;
                sol.push_back(nums[i]);
                sol.push_back(nums[j]);
                sol.push_back(ld);
                ans.insert(sol);
                um[nums[j]] -= 1;
                um[ld] -= 1;
                sol = {};
            }
        }
    }
    vector<vector<int>> mans;
    for (vector<int> v : ans)
    {
        mans.push_back(v);
    }
    return mans;
}

int main()
{
    // vector<int> v = {-1, 0, 1, 2, -1, -4};
    //vector<int> v = {1, 2, -2, -1};
    //vector<int> v = {0, 0, 0};
    vector<int> v = {1, -1, -1, 0};
    //vector<int> v = {-2, 0, 1, 1, 2};
    vector<vector<int>> ans = threeSum(v);
    for (vector<int> triplet : ans)
    {
        for (int value : triplet)
        {
            cout << value << " ";
        }
        cout << "\n";
    }
}