/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9

*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
void dfs(vector<int> &result, int n, int num, int k)
{
    if (n == 0)
    {
        result.push_back(num);
        return;
    }
    int ld = num % 10;
    if (ld - k >= 0)
    {
        dfs(result, n - 1, num * 10 + ld - k, k);
    }
    if (k != 0 && ld + k < 10)
    {
        dfs(result, n - 1, num * 10 + ld + k, k);
    }
}
vector<int> numsSameConsecDiff(int n, int k)
{
    vector<int> result;
    if (n == 1)
        result.push_back(0);
    for (int i = 1; i < 10; i++)
    {
        dfs(result, n - 1, i, k);
    }
    return result;
}