#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
 * processed array -> bool array that represents whether the given node is processed or not. index is the node
 * cost array -> represents the cost of the given node(src->node).  Initially it is INT_MAX
 * parent array -> used to store the parent of the given node.  For backtracking to build the single source shortest path graph
 * source :  
 *      processed[source] = true
 *      cost[source] = 0;
 *      parent[source] = -1
 * update(relax) all the adjacent vertices from the currentNode(source)
 *      if(cost[currentNode] + edgeWeight(currentNode, adjNode) < cost[adjNode]){
 *          cost[adjNode] = cost[currentNode] + edgeWeight(currentNode, adjNode)
 *      }
 * compute the next current to recursively call this logic
 * next current :
 *      next unprocessed minimum cost node 
 * execute the logic with currentNode
 */
int getMin(vector<bool> processed, vector<int> cost)
{
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < cost.size(); ++i)
    {
        if (cost[i] < min && !processed[i])
        {
            min = cost[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void computeDijkstra(vector<vector<pair<int, int>>> adj, int curr, vector<bool> &processed, vector<int> &parent, vector<int> &cost)
{
    processed[curr] = true;
    //update or relax the adjacent vertices from the current node
    for (int i = 0; i < adj[curr].size(); ++i)
    {
        int node = adj[curr][i].first; //pair has node as first and cost to reach the node as second
        int costReq = adj[curr][i].second;
        if (cost[curr] + costReq < cost[node])
        { //if the sum of curr + edge cost is less than the cost in the node then update
            cost[node] = cost[curr] + costReq;
            parent[node] = curr;
        }
    }
    //find the next potential min elem
    curr = getMin(processed, cost);
    if (curr != -1)
    { // returns -1 if all the elements are processed so no need for further calls
        computeDijkstra(adj, curr, processed, parent, cost);
    }
}
int main()
{
    int n = 4;
    vector<vector<pair<int, int>>> adj = {
        {make_pair(1, 3), make_pair(2, 10), make_pair(3, 6)},
        {make_pair(3, 2)},
        {

        },
        {make_pair(2, 2)}};
    vector<bool> processed(n, false);
    vector<int> cost(n, INT_MAX);
    vector<int> parent(n, -1);
    int src = 0;
    cost[0] = 0; //src has no parent so its cost is always 0
    computeDijkstra(adj, src, processed, parent, cost);
    for (int i = 0; i < n; ++i)
    {
        cout << "node " << i << " -> " << cost[i] << " -> " << parent[i] << "\n";
    }
}