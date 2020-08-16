#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *left;
    struct TrieNode *right;
};
struct TrieNode *getNode()
{
    struct TrieNode *newnode = new TrieNode;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct TrieNode *root = getNode();
void insert(int num)
{
    struct TrieNode *curr = root;
    for (int i = 31; i >= 0; --i)
    {
        int bit = (num >> i);
        if ((bit & 1) == 1)
        {
            if (curr->right == NULL)
                curr->right = getNode();
            curr = curr->right;
        }
        else
        {
            if (curr->left == NULL)
                curr->left = getNode();
            curr = curr->left;
        }
    }
}
int findMaxXor(vector<int> arr, int n)
{
    struct TrieNode *curr = root;
    int maxXor = 0;
    for (int i = 0; i < n; i++)
    {
        curr = root;
        int localXor = 0;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (arr[i] >> j) & 1;
            if (bit == 1)
            { //current bit is 1
                if (curr->left)
                {                       //parallel 0 bit is present
                    localXor += 1 << j; //addon to maxXor as the alternate bit is present
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            { //current bit is 0
                if (curr->right)
                {                       //parallel 1 bit is present
                    localXor += 1 << j; //addon to maxXor as the alternate bit is present
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }
        maxXor = max(maxXor, localXor);
    }
    return maxXor;
}
int main()
{
    vector<int> arr = {3, 10, 5, 25, 2, 8};
    for (int val : arr)
    {
        insert(val);
    }
    int maxXor = findMaxXor(arr, arr.size());
    cout << maxXor;
}