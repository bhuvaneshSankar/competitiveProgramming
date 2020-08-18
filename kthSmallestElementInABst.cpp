#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void dfs(Node *root, int &curr, int &target)
{
    if (!root)
        return;
    dfs(root->left, curr, target);
    curr -= 1;
    if (curr == 0)
    {
        target = root->data;
    }
    dfs(root->right, curr, target);
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int k)
{
    //add code here.

    int target, curr = k;
    dfs(root, curr, target);
    if (curr > 0)
        return -1;
    return target;
}