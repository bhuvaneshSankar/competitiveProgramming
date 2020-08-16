//Day 5
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> vec;
    int sum = 0;
    Solution(vector<int> &w)
    {
        vec.push_back(w[0]);
        sum = vec.back();
        for (int i = 1; i < w.size(); i++)
        {
            sum += w[i];
            vec.push_back(sum);
        }
    }

    int pickIndex()
    {
        int randomNumber = rand() % sum;
        int i = 0;
        while (vec[i] <= randomNumber)
        {
            i++;
        }
        return i;
    }
};
