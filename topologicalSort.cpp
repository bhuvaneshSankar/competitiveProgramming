#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
void displayArr(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void dfs(int len, vector<int> adj[], int curr, unordered_set<int> &se, stack<int> &st)
{
    vector<int> v = adj[curr];
    for (int val : v)
    {
        if (se.find(val) == se.end())
        { //element is not present in the set
            se.insert(val);
            dfs(len, adj, val, se, st);
        }
    }
    st.push(curr);
}
int *topoSort(int V, vector<int> adj[])
{
    int n = V;
    int *arr = new int[V];
    unordered_set<int> se;
    stack<int> st;
    int pos = n - 1;
    for (int i = 0; i < V; i++)
    {
        if (se.find(i) == se.end())
        {
            se.insert(i);
            if (adj[i].empty() == true)
            {
                st.push(i);
            }
            else
            {
                dfs(V, adj, i, se, st);
            }
        }
    }
    int i = 0;
    while (!st.empty())
    {
        arr[i++] = st.top();
        st.pop();
    }

    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a = {};
    vector<int> b = {3};
    vector<int> c = {3};
    vector<int> d = {};
    vector<int> e = {0, 1};
    vector<int> f = {0, 2};
    vector<int> adj[] = {a, b, c, d, e, f};
    int V = 6; //number of vertices
    int *arr = topoSort(V, adj);
    for (int i = 0; i < V; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}