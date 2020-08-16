#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printSparseTable(vector<vector<int>> &sparse, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            cout << sparse[i][j] << " ";
        }
        cout << "\n";
    }
}
void generateSparseTable(vector<int> v, int len, int col, vector<vector<int>> &sparse)
{
    for (int j = 0; j <= col; j++)
    {
        for (int i = 0; i < len; i++)
        {
            if (j == 0)
            {
                sparse[i][j] = v[i];
                continue;
            }
            if (i + (1 << j) <= len)
            {
                int v1 = sparse[i][j - 1];
                int val = (i + (1 << (j - 1)));
                int v2 = sparse[val][j - 1];
                sparse[i][j] = v1 < v2 ? v1 : v2;
            }
        }
    }
}

int findRM(vector<vector<int>> &sparse, int l, int r)
{
    int len = r - l + 1;
    int k = log2(len);
    int rangeMinimum = sparse[l][k];
    int left = len - (1 << k);
    if (left > 0)
    {
        left += l;
        rangeMinimum = min(rangeMinimum, sparse[left][k]);
    }
    return rangeMinimum;
}
int main()
{
    vector<int> v = {10, 5, 11, 3, 8, 13, 6, 1, 4, 2};
    int len = v.size();
    int col = (int)(log2(len));
    vector<vector<int>> sparse(len, vector<int>(col));
    generateSparseTable(v, len, col, sparse);
    printSparseTable(sparse, len, col);

    cout << findRM(sparse, 0, 9) << "\n";
    cout << findRM(sparse, 1, 8) << "\n";
    cout << findRM(sparse, 2, 5) << "\n";
    cout << findRM(sparse, 0, 2) << "\n";
    cout << findRM(sparse, 0, 0) << "\n";
}
