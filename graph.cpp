#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> adj, vector<int> dfsCurr, vector<vector<int>> &totalDfs, int curr, vector<bool> vis, int n)
{
    dfsCurr.push_back(curr);
    vis[curr] = true;
    bool isTrav = false;
    for (int i = 0; i < adj[curr].size(); ++i)
    {
        int node = adj[curr][i];
        if (!vis[node])
        {
            isTrav = true;
            dfs(adj, dfsCurr, totalDfs, node, vis, n);
        }
    }
    if (!isTrav) //if there is no outgoing edges from current node the dfs stops here, so add the dfs vector to total dfs vector
    {
        totalDfs.push_back(dfsCurr);
    }
    dfsCurr.pop_back(); //pop_back the current node after execution to avoid duplicate entries of current node
}
void dfs(vector<vector<int>> adj, vector<vector<int>> &totalDfs, int n)
{
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        vector<bool> vis(n, false);
        vector<int> currDfs;
        st.push(i);
        while (!st.empty())
        {
            int val = st.top();
            st.pop();
            vis[val] = true;
            currDfs.push_back(val);
            cout << val << " ";
            bool isTrav = false;
            for (int i = 0; i < adj[val].size(); ++i)
            {
                if (!vis[adj[val][i]])
                {
                    isTrav = true;
                    st.push(adj[val][i]);
                }
            }
            vis[val] = false;
            currDfs.pop_back();
        }
        cout << "\n";
    }
}
void dfsUtil(vector<vector<int>> adj, int n)
{
    vector<vector<int>> totalDfs;
    dfs(adj, totalDfs, n);
    // for (vector<int> dfs : totalDfs)
    // {
    //     for (int val : dfs)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < adj.size(); ++i)
    // {
    //     vector<bool> vis(n, false);
    //     vis[i] = true;
    //     vector<int> dfsCurr;
    //     vector<vector<int>> totalDfs;
    //     dfs(adj, dfsCurr, totalDfs, i, vis, n);
    //     for (vector<int> dfs : totalDfs)
    //     {
    //         for (int val : dfs)
    //         {
    //             cout << val << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
}
int main()
{
    int n = 7;
    vector<vector<int>> adj = {{1, 3}, {2, 4}, {5, 6}, {1, 4}, {2, 6}, {6}, {}};
    dfsUtil(adj, n);
}