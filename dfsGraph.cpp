#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <algorithm>
#define vi vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(val) cout << #val << " - " << val << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n"
using namespace std;

void dfsUtil(vector<vi> adj, int n)
{
    fo(i, n)
    {
        stack<int> st;
        set<int> se;
        st.push(i);
        bool visited[n];
        for (int j = 0; j < n; j++)
        {
            visited[i] = false;
        }
        while (!st.empty())
        {
            int val = st.top();
            st.pop();
            if (visited[val] == false)
            {
                se.insert(val);
                visited[val] = false;
            }
            vi list = adj[val];
            for (vi::iterator itr = list.begin(); itr != list.end(); itr++)
            {
                val = *itr;
                if (visited[val] == false)
                {
                    se.insert(val);
                }
            }
        }
        cout << "dfs\n";
        for (auto it = se.begin(); it != se.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    vector<vi> adj = {{1, 2}, {2}, {0, 3}, {3}};
    //vector<vector<int>> adj = {{1}, {3, 5}, {}, {4}, {5}};
    dfsUtil(adj, n);
}