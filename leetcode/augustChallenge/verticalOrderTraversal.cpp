/*
    Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
    If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
*/
#include <bits/stdc++.h>
#include <vector>
#include <map>
#define n 1001
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
struct TreeNode *root;
struct TreeNode *getNode(int val)
{
    TreeNode *newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

static int max(int a, int b)
{
    return a > b ? a : b;
}
static int min(int a, int b)
{
    return a < b ? a : b;
}
void dfs(TreeNode *current, int val, int level, unordered_map<int, vector<int>[n]> &pairs, int &maxLevel, int &minC, int &maxC)
{
    if (current != NULL)
    {
        minC = min(minC, val);
        maxC = max(maxC, val);
        maxLevel = max(level, maxLevel);
        pairs[val][level].push_back(current->val);
        dfs(current->left, val - 1, level + 1, pairs, maxLevel, minC, maxC);
        dfs(current->right, val + 1, level + 1, pairs, maxLevel, minC, maxC);
    }
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{

    unordered_map<int, vector<int>[n]> pairs;
    vector<vector<int>> result;
    int maxLevel = -1, minC = 1, maxC = 0;
    dfs(root, 0, 1, pairs, maxLevel, minC, maxC);
    for (int i = minC; i <= maxC; i++)
    {
        vector<int> *res = pairs[i];
        vector<int> vi;
        for (int i = 0; i <= maxLevel; i++)
        {
            if (res[i].size() > 0)
            {
                sort(res[i].begin(), res[i].end());
                for (int j = 0; j < res[i].size(); j++)
                {
                    vi.push_back(res[i][j]);
                }
            }
        }
        if (vi.size() > 0)
        {
            result.push_back(vi);
        }
    }
    return result;
}

int main()
{
    root = getNode(1);
    root->left = getNode(2);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right = getNode(3);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->right->right->left = getNode(8);
    root->right->right->right = getNode(9);
    vector<vector<int>> result = verticalTraversal(root);
    cout << "size " << result.size() << "\n";
    for (vector<int> vi : result)
    {
        for (int val : vi)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
}
