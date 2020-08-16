/*
 You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

how to : initiate a dfs from each node and check if the targetSum can be formed
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
int gc;
void dfs(TreeNode *currentNode, int prevSum, int targetSum)
{
    if (currentNode != NULL)
    {
        if (prevSum + currentNode->val == targetSum)
        {
            gc++;
        }
        dfs(currentNode->left, prevSum + currentNode->val, targetSum);
        dfs(currentNode->right, prevSum + currentNode->val, targetSum);
    }
}
//o(n^2)
void dfsUtil(TreeNode *currentNode, int targetSum)
{
    if (currentNode != NULL)
    {
        dfs(currentNode, 0, targetSum);
        dfsUtil(currentNode->left, targetSum);
        dfsUtil(currentNode->right, targetSum);
    }
}

//o(nlogn)
vector<int> vi;
static void dfsUtil(TreeNode *currentNode, int targetSum)
{
    if (currentNode != NULL)
    {
        vi.push_back(currentNode->val);
        dfsUtil(currentNode->left, targetSum);
        dfsUtil(currentNode->right, targetSum);
        int temp = 0;
        for (int i = vi.size() - 1; i >= 0; i--)
        {
            temp += vi[i];
            if (temp == targetSum)
            {
                gc++;
            }
        }
        vi.pop_back();
    }
}
int pathSum(TreeNode *root, int sum)
{
    dfsUtil(root, sum);
    int result = gc;
    gc = 0;
    return result;
}