/*
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int n, long int &count, int l, int mid, int r);
void countInversions(vector<int> &arr, int n, long int &count, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        countInversions(arr, n, count, l, mid);
        countInversions(arr, n, count, mid + 1, r);
        merge(arr, n, count, l, mid, r);
    }
}
void merge(vector<int> &arr, int n, long int &count, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> a1(n1);
    vector<int> a2(n2);
    for (int i = 0; i < n1; ++i)
    {
        a1[i] = arr[i + l];
    }
    for (int j = 0; j < n2; ++j)
    {
        a2[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {

        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            ++i;
        }
        else
        {
            arr[k] = a2[j];
            ++j;
            count += (mid - (l + i) + 1);
        }
        ++k;
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = a2[j];
        ++j;
        ++k;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            int val;
            cin >> val;
            arr[i] = val;
        }
        long int count = 0;
        countInversions(arr, n, count, 0, n - 1);
        cout << count << "\n";
    }
    return 0;
}