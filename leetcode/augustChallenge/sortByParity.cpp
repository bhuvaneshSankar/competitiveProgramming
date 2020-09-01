#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
class Solution
{

public:
    struct Comp
    {
        bool operator()(int a, int b)
        {
            if (a % 2 == 0)
            {
                return true;
            }
            return false;
        }
    };
    vector<int> sortArrayByParity(vector<int> &ar)
    {
        // sort(ar.begin(), ar.end(), comp);
        set<int, Comp> st;
        for (int val : ar)
        {
            st.insert(val);
        }
        vector<int> arr(ar.size());
        int i = 0;
        for (int val : st)
        {
            arr[i++] = val;
        }
        return arr;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 4, 3, 1, 7, 4};
    vector<int> res = sol.sortArrayByParity(arr);
    for (int val : res)
    {
        cout << val << " ";
    }
    cout << "\n";
}