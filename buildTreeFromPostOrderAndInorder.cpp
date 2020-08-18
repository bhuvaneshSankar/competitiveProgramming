#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int search(int in[], int l, int r, int ti)
{
    for (int i = l; i <= r; i++)
    {
        if (in[i] == ti)
        {
            return i;
        }
    }
}
struct Node *getNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int pos;
struct Node *constructTree(int in[], int po[], int l, int r)
{
    if (l > r)
        return NULL;
    struct Node *newnode = getNode(po[pos]);
    int ti = search(in, l, r, po[pos]);
    pos--;
    if (l == r)
        return newnode;
    newnode->right = constructTree(in, po, ti + 1, r);
    newnode->left = constructTree(in, po, l, ti - 1);
    return newnode;
}
void dfs(struct Node *root)
{
    if (root != NULL)
    {
        dfs(root->left);
        cout << root->data << " ";
        dfs(root->right);
    }
}
Node *buildTree(int in[], int post[], int n)
{
    pos = n - 1;
    struct Node *root = constructTree(in, post, 0, n - 1);
    return root;
}
