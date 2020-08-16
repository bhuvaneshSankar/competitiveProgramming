#include <bits/stdc++.h>
using namespace std;

Node *lca(Node *root, int n1, int n2)
{
    unordered_map<Node *, int> um;
    bool found = false;
    dfs(root, n1, um, found);
    if (found == false)
        return NULL;
    found = false;
    Node *targetNode = NULL;
    //  dfs1(root, n2, um, found, targetNode);
    return targetNode;
}