#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return arr;
    int maxi = 1;
    int maxIndex = 0;
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > maxi)
                    {
                        maxi = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
    }
    vector<int> v;
    int j = maxIndex;
    int prev = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == maxi && (prev % arr[i] == 0 || prev == -1))
        {
            v.push_back(arr[i]);
            maxi--;
            prev = arr[i];
        }
    }
    return v;
}
int main()
{
    //   vector<int> v = {1, 2, 3};
    vector<int> v = {3, 4, 16, 8};
    //vector<int> v = {1, 2, 4, 8};
    vector<int> a = largestDivisibleSubsetOpt(v);
    cout << "size " << a.size() << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}