#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

//check if common factor exists between a and b
bool isCfExists(int a, int b)
{
    if (a == 1 || b == 1)
    {
        return false;
    }
    else if (((a % 2) == 0) && ((b % 2) == 0) || a == b || a % b == 0 || b % a == 0)
    {
        return true;
    }
    else
    {
        int t1 = min(a, b);
        int t2 = max(a, b);
        a = t1;
        b = t2;
        for (int i = 3; i <= a / 2; i += 2)
        {
            if ((a % i == 0) && (b % i == 0))
            {
                return true;
            }
        }
    }
    return false;
}
void buildGraph(vector<int> &arr, int n, unordered_map<int, vector<int>> &graph)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << "\n";
        for (int j = i + 1; j < n; ++j)
        {
            if (isCfExists(arr[i], arr[j]))
            {
                graph[arr[i]].push_back(arr[j]);
                graph[arr[j]].push_back(arr[i]);
            }
        }
    }
}
void printGraph(unordered_map<int, vector<int>> &graph)
{
    for (pair<int, vector<int>> node : graph)
    {
        cout << "node " << node.first << "\n";
        for (int edge : node.second)
        {
            cout << edge << " ";
        }
        cout << "\n";
    }
}
void dfs(unordered_map<int, vector<int>> &graph, int curr, int &cnt, unordered_map<int, bool> &visited)
{
    cout << curr << " ";
    vector<int> edges = graph[curr];
    cout << "edges \n";
    for (int val : edges)
    {
        cout << val << " ";
    }
    cout << "\n";
    for (int node : edges)
    {
        if (visited[node] == false)
        {
            visited[node] = true;
            cnt += 1;
            dfs(graph, node, cnt, visited);
        }
    }
}
int getLargestComponentSize(unordered_map<int, vector<int>> &graph, vector<int> nodes, int n)
{
    int i = 0;
    int cnt = 0;
    unordered_map<int, bool> visited;
    for (int val : nodes)
    {
        visited[val] = false;
    }
    int gmax = 0;
    for (int val : nodes)
    {
        int count = 1;
        if (visited[val] == false)
        {
            visited[val] = true;
            dfs(graph, val, count, visited);
        }
        cout << "count " << count << "\n";
        gmax = max(gmax, count);
    }
    return gmax;
}
int main()
{
    cout << " is " << isCfExists(6, 15) << "\n";

    // vector<int> arr = {2, 3, 6, 7, 4, 12, 21, 39};
    // vector<int> arr = {20, 50, 9, 63};
    // vector<int> arr = {4, 6, 15, 35};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = arr.size();
    unordered_map<int, vector<int>> graph;
    buildGraph(arr, n, graph);
    printGraph(graph);
    int largestComponentSize = getLargestComponentSize(graph, arr, n);
    cout << largestComponentSize << " ";
}