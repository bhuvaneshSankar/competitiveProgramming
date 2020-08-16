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

ll gCost = INT_MAX;
bool flag = false;
void dfs(int n, vector<vector<vector<int>>> &adj, int curr, int d, int k, int stop, ll cost, bool vis[])
{
    vis[curr] = true;
    if (curr == d && stop - 1 <= k)
    {
        flag = true;
        gCost = min(gCost, cost);
        vis[curr] = false;
        return;
    }
    if ((flag == true && cost > gCost) || stop - 1 > k)
    {
        vis[curr] = false;
        return;
    }
    for (int i = 0; i < adj[curr].size(); i++)
    {
        int dest = adj[curr][i][0];
        if (vis[dest] == false)
        {
            dfs(n, adj, dest, d, k, stop + 1, cost + adj[curr][i][1], vis);
        }
    }
    vis[curr] = false;
}

void constructAdjList(vector<vector<vector<int>>> &adj, int n, vector<vector<int>> flights)
{
    for (int i = 0; i < flights.size(); i++)
    {
        vector<vector<int>> vec = adj[flights[i][0]];
        vector<int> v(2);
        v[0] = flights[i][1];
        v[1] = flights[i][2];
        vec.push_back(v);
        adj[flights[i][0]] = vec;
    }
}
void printAdj(vector<vector<vector<int>>> adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << "i = " << i << nl;
        vector<vector<int>> v = adj[i];
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j][0] << " " << v[j][1] << nl;
        }
    }
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<vector<int>>> adj(n);
    constructAdjList(adj, n, flights);
    bool visited[n];
    memset(visited, false, n);
    dfs(n, adj, src, dst, K, 0, 0, visited);
    if (flag == false)
    {
        return -1;
    }
    ll lCost = gCost;
    gCost = INT_MAX;
    flag = false;
    return lCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 10;
    vector<vector<int>> flights = {{3, 4, 4}, {2, 5, 6}, {4, 7, 10}, {9, 6, 5}, {7, 4, 4}, {6, 2, 10}, {6, 8, 6}, {7, 9, 4}, {1, 5, 4}, {1, 0, 4}, {9, 7, 3}, {7, 0, 5}, {6, 5, 8}, {1, 7, 6}, {4, 0, 9}, {5, 9, 1}, {8, 7, 3}, {1, 2, 6}, {4, 1, 5}, {5, 2, 4}, {1, 9, 1}, {7, 8, 10}, {0, 4, 2}, {7, 2, 8}};

    //vector<vector<int>> flights = {{1, 2, 10}, {2, 0, 7}, {1, 3, 8}, {4, 0, 10}, {3, 4, 2}, {4, 2, 10}, {0, 3, 3}, {3, 1, 6}, {2, 4, 5}};
    int src = 6;
    int dest = 0, k = 7;
    findCheapestPrice(n, flights, src, dest, k);
}

/*
{{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}}
 {{1, 2, 10}, {2, 0, 7}, {1, 3, 8}, {4, 0, 10}, {3, 4, 2}, {4, 2, 10}, {0, 3, 3}, {3, 1, 6}, {2, 4, 5}};
{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
*/