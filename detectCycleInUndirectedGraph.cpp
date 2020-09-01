/*
Approach - Use disjoint set datastructures and for every edge call union set.
           If the parent of two vertices in the edges are same then there exists a cycle in the graph
*/
#include <bits/stdc++.h>
#include <map>
using namespace std;
struct dsetNode
{
    int data;
    int rank;
    struct dsetNode *parent;
};
map<int, struct dsetNode *> dsmap;
void makeSet(int val)
{
    struct dsetNode *newnode = (struct dsetNode *)malloc(sizeof(struct dsetNode));
    newnode->data = val;
    newnode->rank = 0;
    newnode->parent = newnode;
    dsmap.insert({val, newnode});
}
struct dsetNode *getdsetNode(int val)
{
    return dsmap[val];
}
struct dsetNode *findSet(int val)
{
    dsetNode *node = getdsetNode(val);
    if (node->parent == node)
    {
        return node;
    }
    node->parent = findSet(node->parent->data);
    return node->parent;
}
bool unionSet(int v1, int v2)
{
    struct dsetNode *p1 = (struct dsetNode *)findSet(v1);
    struct dsetNode *p2 = (struct dsetNode *)findSet(v2);
    if (p1 == p2)
    {
        return false;
    }
    if (p1->rank > p2->rank)
    {
        p2->parent = p1;
    }
    else if (p2->rank > p1->rank)
    {
        p1->parent = p2;
    }
    else
    {
        p1->rank += 1;
        p2->parent = p1;
    }
    return true;
}
bool isCyclic(vector<int> g[], int n)
{
    dsmap.clear();
    for (int i = 0; i < n; ++i)
    {
        makeSet(i);
    }
    set<pair<int, int>> visited;
    for (int i = 0; i < n; ++i)
    {
        vector<int> vi = g[i];
        for (int j : vi)
        {
            auto it1 = visited.insert({i, j}); //as it is a undirected graph the edges exist such as 2,1 and 1,2.  So taking only one edge into consideration is enough.
            auto it2 = visited.insert({j, i});
            if (it1.second == false || it2.second == false)
            {
                continue;
            }
            bool res = unionSet(i, j);
            if (res == false)
            {
                return true;
            }
        }
    }
    return false;
}