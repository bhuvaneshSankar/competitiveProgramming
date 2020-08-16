#include <bits/stdc++.h>
#include <vector>

using namespace std;

int calculateSizeOfArray(int n)
{
    if (__builtin_popcount(n) == 1)
    { //power of 2
        return n * 2 - 1;
    }
    else
    {
        for (int i = 0;; i++)
        {
            if ((1 << i) > n)
            {
                return (1 << i) * 2 - 1;
            }
        }
    }
}
void print(vector<int> segmentTree)
{
    cout << "Segment Tree" << endl;
    for (int i = 0; i < segmentTree.size(); i++)
    {
        cout << segmentTree[i] << " ";
    }
    cout << endl;
}
void constructTree(vector<int> arr, vector<int> &segmentTree, int left, int right, int pos)
{
    if (left == right)
    {
        segmentTree[pos] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    constructTree(arr, segmentTree, left, mid, 2 * pos + 1);
    constructTree(arr, segmentTree, mid + 1, right, 2 * pos + 2);
    segmentTree[pos] = segmentTree[pos * 2 + 1] + segmentTree[2 * pos + 2];
}

int calcSumOfGivenRange(vector<int> segmentTree, int low, int high, int rl, int rr, int pos)
{
    if (low >= rl && high <= rr)
    { //total overlap
        return segmentTree[pos];
    }
    else if (low > rr || high < rl)
    { //no overlap
        return 0;
    }
    int mid = (low + high) / 2;
    return calcSumOfGivenRange(segmentTree, low, mid, rl, rr, pos * 2 + 1) + calcSumOfGivenRange(segmentTree, mid + 1, high, rl, rr, pos * 2 + 2);
}
void update(vector<int> &segmentTree, int targetPos, int targetValue, int low, int high, int pos)
{
    if (low == targetPos && low == high)
    {
        segmentTree[pos] = targetValue;
        return;
    }
    int mid = (low + high) / 2;
    if (targetPos <= mid)
    {
        update(segmentTree, targetPos, targetValue, low, mid, pos * 2 + 1);
    }
    else
    {
        update(segmentTree, targetPos, targetValue, mid + 1, high, pos * 2 + 2);
    }
    segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
}
void query(vector<int> arr, vector<int> &segmentTree, int n, char type)
{
    if (type == 'q')
    {
        int rl, rr;
        cin >> rl >> rr;
        int rangeSum = calcSumOfGivenRange(segmentTree, 0, n - 1, rl, rr, 0);
        cout << "rangeSum " << rangeSum << endl;
    }
    else if (type == 'u')
    {
        int targetPos, targetValue;
        cin >> targetPos >> targetValue;
        update(segmentTree, targetPos, targetValue, 0, n - 1, 0);
        print(segmentTree);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sizeOfSegmentTree = 15;
    sizeOfSegmentTree = calculateSizeOfArray(n);

    cout << "size " << sizeOfSegmentTree;
    vector<int> segmentTree(sizeOfSegmentTree, 0);
    constructTree(arr, segmentTree, 0, n - 1, 0);
    char typeOfQuery;
    int choice = 1;
    do
    {
        cout << "Enter type of query" << endl;
        cin >> typeOfQuery;
        query(arr, segmentTree, n, typeOfQuery);
        cout << "Press 1 to continue, any other key to exit" << endl;
        cin >> choice;
        cout << "your choice = " << choice << endl;
    } while (choice == 1);
}