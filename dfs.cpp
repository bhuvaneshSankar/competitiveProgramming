#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator

using namespace std;
void dfs(vector<vi> adj, int n)
{
    for (int i = 0; i < n; i++)
    {
        stack<int> st;
        vi v;
        st.push(i);
        bool visited[n];
        memset(visited, 0, n);
        while (st.empty() == false)
        {
            int val = st.top();
            st.pop();
            if (visited[val] == false)
            {
                visited[val] = true;
                v.push_back(val);
            }
            vi ve = adj[val];
            foj(j, ve.size())
            {
                if (visited[ve[j]] == false)
                {
                    st.push(ve[j]);
                }
            }
        }
        foj(j, v.size())
        {
            cout << v[j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 6;
    //vector<vi> adj = {{1, 2}, {2}, {0, 3}, {3}};
    vector<vector<int>> adj = {{1}, {3, 5}, {}, {4}, {5}, {1, 4}};
    dfs(adj, n);
}