#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator
#define nl "\n"

using namespace std;

void dfs(vi adj[], int n, int curr, stack<int> &sv, vector<bool> &vis)
{
    vis[curr] = true;
    vi v = adj[curr];
    foi(i, v.size())
    {
        if (vis[v[i]] == false)
        {
            dfs(adj, n, v[i], sv, vis);
        }
    }
    sv.push(curr);
}
void sortVertices(vi adj[], int n, stack<int> &sv)
{
    vector<bool> vis(n, false);
    foi(i, n)
    {
        if (vis[i] == false)
            dfs(adj, n, i, sv, vis);
    }
}
void printStack(stack<int> st)
{
    while (st.empty() == false)
    {
        int top = st.top();
        st.pop();
        cout << top << " ";
    }
    cout << "\n";
}

vector<vi> transpose(vi adj[], int n)
{
    vector<vi> trans(n);
    foi(i, n)
    {
        int source = i;
        vi v = adj[i];
        foj(j, v.size())
        {
            int dest = v[j];
            trans[dest].push_back(source);
        }
    }
    return trans;
}
void dfs2(vector<vi> trans, int curr, vector<bool> &vis)
{
    vis[curr] = true;
    cout << curr << " ";
    vi v = trans[curr];
    foi(i, v.size())
    {
        if (vis[v[i]] == false)
        {
            dfs2(trans, v[i], vis);
        }
    }
}
void solve(vi adj[], int n)
{
    //step 1 - Sort the vertices acccording to their finishing time.
    //Use Dfs to find this by inserting a vertex after doing dfs to all of its adj vertices;
    stack<int> sv;
    sortVertices(adj, n, sv);
    printStack(sv);

    //step 2 - find transpose of the graph
    vector<vi> trans = transpose(adj, n);

    //step 3 - find scc by doing dfs for trans
    int scc = 0;
    vector<bool> vis(n, false);
    while (sv.empty() == false)
    {
        int curr = sv.top();
        sv.pop();
        if (vis[curr] == false)
        {
            scc++;
            cout << "SCC ";
            dfs2(trans, curr, vis);
            cout << nl;
        }
    }
    deb(scc);
}
int main()
{
    // int n = 5;
    // vi adj[n];
    // adj[0] = {1, 3};
    // adj[1] = {2};
    // adj[2] = {0};
    // adj[3] = {4};

    // int n = 4;
    // vi adj[n];
    // adj[0] = {1, 2};
    // adj[1] = {2};

    int n = 11;
    vi adj[n];
    adj[0] = {1};
    adj[1] = {2, 3};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {5};
    adj[5] = {3};
    adj[6] = {5, 7};
    adj[7] = {8};
    adj[8] = {9};
    adj[9] = {6, 10};

    solve(adj, n);
}