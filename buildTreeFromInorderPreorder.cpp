#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *getNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int search(int in[], int l, int r, int tg)
{
    for (int i = l; i <= r; i++)
    {
        if (in[i] == tg)
        {
            return i;
        }
    }
}
int pos = 0;
Node *constructTree(int in[], int pre[], int l, int r)
{
    if (l > r)
        return NULL;
    Node *newnode = getNode(pre[pos]);

    int ti = search(in, l, r, pre[pos]);
    pos++;
    if (l == r)
        return newnode;
    newnode->left = constructTree(in, pre, l, ti - 1);
    newnode->right = constructTree(in, pre, ti + 1, r);
    return newnode;
}

Node *buildTree(int in[], int pre[], int n)
{
    struct Node *root = constructTree(in, pre, 0, n - 1);
    pos = 0;
    return root;
}