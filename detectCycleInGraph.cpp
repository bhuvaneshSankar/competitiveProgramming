#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator

using namespace std;

bool util(int n, vector<int> adj[], int curr, bool vis[], unordered_set<int> &vs)
{
    vis[curr] = true;
    vi v = adj[curr];

    foi(i, v.size())
    {
        if (vis[v[i]] == true)
        {
            return true;
        }
        if (vs.find(v[i]) == vs.end())
        { //check whether the vertex is already visited
            bool flag = util(n, adj, v[i], vis, vs);
            if (flag == true)
            {
                return true;
            }
        }
    }
    vis[curr] = false;
    vs.insert(curr); //its clear that a cycle cant be formed from this vertex so insert it into a set so that recomputation for this same vertex can be avoided
    return false;
}
//unordered set vs.  It is used to avoid the recomputation of a same vertice multiple times  refer line 28
bool isCyclic(int n, vector<int> adj[])
{
    unordered_set<int> vs;
    foi(i, n)
    {
        if (vs.find(i) == vs.end()) //check whether the vertex is already visited
        {
            bool vis[n];
            memset(vis, 0, n);
            bool flag = util(n, adj, i, vis, vs);
            if (flag == true)
            {
                return true;
            }
        }
    }
    return false; //no cycle present
}

void solve()
{
    int n; //number of vertices
    cin >> n;
    vi adj[n];
    int e; //number of edges
    cin >> e;
    foi(i, e)
    {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
    }
    cout << isCyclic(n, adj) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}

/*
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
*/
