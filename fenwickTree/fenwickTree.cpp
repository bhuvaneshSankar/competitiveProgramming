#include <bits/stdc++.h>
#include <vector>
#define vi vector<int>
using namespace std;

void update(int pos, int add, vi &arr, int len)
{
    pos = pos + 1;
    while (pos < len)
    {
        arr[pos] += add;
        pos = pos + (pos & (-pos));
    }
}

int sum(int pos, vi arr, int len)
{
    int res = 0;
    while (pos > 0)
    {
        res += arr[pos];
        pos = pos - (pos & (-pos));
    }
    return res;
}

int rangeSum(int start, int end, vi arr, int len)
{
    start = start + 1; //fenwick arr index starts from 1
    end = end + 1;
    int s1 = sum(end, arr, len);
    int s2 = sum(start - 1, arr, len);
    cout << "s1 = " << s1 << " " << s2 << " " << s2 << "\n";
    return s1 - s2;
}

/**
 * returns the lower bound position
 * how to : find the index which is lesser than the val for which the lower bound is to be found
 * so the next index will be lower bound, so return curr+1
 */

int getLowerBoundPos(int val, vi fenwickArr, int len)
{
    int curr = 0, prevSum = 0;
    for (int i = log2(len); i >= 0; i--)
    {
        if (fenwickArr[curr + (1 << i)] + prevSum < val)
        {
            curr = curr + 1 << i;
            prevSum += fenwickArr[curr];
        }
    }
    return curr + 1;
}

//returns value at the specified position
int readSingle(int idx, vi &fenwickArr)
{
    idx++;
    int sum = fenwickArr[idx]; // this sum will be decreased
    if (idx > 0)
    { // the special case
        int z = idx - (idx & -idx);
        cout << "idx " << idx << "\n";
        idx--; // idx is not important anymore, so instead y, you can use idx
        while (idx != z)
        { // at some iteration idx (y) will become z
            cout << "idx " << idx << "\n";
            sum -= fenwickArr[idx];
            // substruct fenwickArr frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void constructFenwickArr(vi &fenwickArr, vi arr, int n)
{
    int fl = n + 1; //fenwick arr length
    for (int i = 0; i < n; i++)
    {
        update(i, arr[i], fenwickArr, fl);
    }
}
void printArr(vi arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n = 16;
    vi arr = {10, 8, 12, 3, 5, 10, 23, 11, 2, 90, 21, 78, 32, 4, 16, 89};
    vi fenwickArr(n + 1);
    constructFenwickArr(fenwickArr, arr, n);
    printArr(fenwickArr, n + 1);
    int res = readSingle(15, fenwickArr);
    cout << "single " << res << "\n";
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Enter u for update and s for sum\n";
        char option;
        cin >> option;
        if (option == 'u')
        {
            int pos, val;
            cout << "Enter the position\n";
            cin >> pos;
            cout << "Enter the value to update\n";
            cin >> val;
            val = val - arr[pos];
            arr[pos] = arr[pos] + val;
            update(pos, val, fenwickArr, n + 1);
        }
        else if (option == 's')
        {
            int startRange, endRange;
            cout << "Enter the starting range and the ending range\n";
            cin >> startRange;
            cin >> endRange;
            int result = rangeSum(startRange, endRange, fenwickArr, n + 1);
            cout << "range sum = " << result << "\n";
        }
        else
        {
            cout << "Enter correct option\n";
        }
        cout << "Press y for continue and any other to exit \n";
        cin >> ch;
    }
}