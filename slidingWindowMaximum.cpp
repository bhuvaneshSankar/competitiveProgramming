/*
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element are as 3, 4, 5, 5, 5 and 6.


*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void swm(vector<int> arr, int n, int k)
{
    deque<int> dq;
    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
    for (int i = k; i < n; ++i)
    {
        int top = dq.front();
        if (top <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        cout << arr[dq.front()] << " ";
    }
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> arr(n);
        int val;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            arr[i] = val;
        }
        swm(arr, n, k);
        cout << "\n";
    }
    return 0;
}