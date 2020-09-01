#include <bits/stdc++.h>
#include <vector>
using namespace std;
void reverse(vector<int> &arr, int l, int r)
{
    while (l < r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
vector<int> pancakeSort(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    for (int i = 0; i < n - 1; ++i)
    {
        int max = n - i;
        int end = n - i;
        int pos;
        for (int j = 0; j < end; ++j)
        {
            if (arr[j] == max)
            {
                pos = j;
                break;
            }
        }
        res.push_back(pos + 1);
        reverse(arr, 0, pos);
        reverse(arr, 0, end - 1);
        res.push_back(end);
    }
    return res;
}
int main()
{
    vector<int> arr = {3, 2, 4, 1};
    vector<int> res = pancakeSort(arr);
    for (int val : res)
    {
        cout << val << " ";
    }
    cout << "\n";
}