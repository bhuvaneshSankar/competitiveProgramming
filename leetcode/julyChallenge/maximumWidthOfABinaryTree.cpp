#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
unsigned long long int max(unsigned long long int a, unsigned long long int b)
{
    return a > b ? a : b;
}
int widthOfBinaryTree(TreeNode *root)
{
    long long maxWidth = 0;
    queue<pair<TreeNode *, unsigned long long int>> q;
    if (root != NULL)
    {
        pair<TreeNode *, unsigned long long int> p;
        p.first = root;
        p.second = 0;
        q.push(p);
        while (!q.empty())
        {
            long long size = q.size();
            pair<TreeNode *, unsigned long long int> first = q.front();
            pair<TreeNode *, unsigned long long int> last = q.front();
            while (size > 0)
            {
                --size;
                last = q.front();
                TreeNode *node = last.first;
                unsigned long long int index = last.second;
                q.pop();
                if (node->left != NULL)
                {
                    q.push(make_pair(node->left, (index * 2)));
                }
                if (node->right != NULL)
                {
                    q.push(make_pair(node->right, (index * 2) + 1));
                }
            }
            maxWidth = max(maxWidth, last.second - first.second + 1);
        }
    }
    return maxWidth;
}