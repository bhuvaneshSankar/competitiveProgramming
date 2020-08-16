//Day 3
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

struct node
{
    int diff;
    int index;
};
//naive - backtracking - o(2pow(sizeof(costs)))
int globalSum = INT_MAX;
void twoCityScheduledCosts(vector<vector<int>> &costs, int sum, int pos, int n, int n1, int n2)
{
    if (pos == costs.size())
    {
        if (sum < globalSum)
        {
            globalSum = sum;
        }
        return;
    }
    int localSum;
    if (n1 < n && n2 < n)
    {
        localSum = sum + costs[pos][0];
        twoCityScheduledCosts(costs, localSum, pos + 1, n, n1 + 1, n2);
        localSum = sum + costs[pos][1];
        twoCityScheduledCosts(costs, localSum, pos + 1, n, n1, n2 + 1);
    }
    else if (n1 < n)
    {
        localSum = sum + costs[pos][0];
        twoCityScheduledCosts(costs, localSum, pos + 1, n, n1 + 1, n2);
    }
    else
    {
        localSum = sum + costs[pos][1];
        twoCityScheduledCosts(costs, localSum, pos + 1, n, n1, n2 + 1);
    }
}

int solveUsingSort(vector<vector<int>> &costs) //o(nlogn)
{
    multimap<int, vector<int>> costMap;
    int n = costs.size();
    for (int i = 0; i < n; i++) //  o(nlogn)
    {
        int profit = costs[i][1] - costs[i][0];
        costMap.insert({profit, costs[i]}); //  o(logn)
    }
    int pos = 0, sum = 0;
    for (auto it : costMap) // o(n)
    {
        if (pos < n / 2)
        {
            sum += it.second[1];
        }
        else
        {
            sum += it.second[0];
        }
        pos++;
    }
    return sum;
}
int getParent(int i)
{
    return (i - 1) / 2;
}
int getLeftChild(int i)
{
    return (i * 2) + 1;
}
int getRightChild(int i)
{
    return (i * 2) + 2;
}
void printHeap(vector<struct node *> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        struct node *current = heap[i];
        cout << current->index << " " << current->diff << "\n";
    }
    cout << "\n";
}
void buildMaxHeap(vector<vector<int>> &costs, int n, vector<struct node *> &heap)
{
    for (int i = 0; i < n; i++)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->index = i;
        newnode->diff = b - a;
        heap[i] = newnode;
        int parent, leftChild, rightChild;
        parent = getParent(i);
        struct node *currentNode = newnode;
        int curr = i;
        while (parent >= 0)
        {
            struct node *parentNode = heap[parent];
            if (parentNode->diff < currentNode->diff)
            {
                struct node *temp = parentNode;
                heap[parent] = newnode;
                heap[curr] = parentNode;
                //    printHeap(heap);
                if (parent == 0)
                    break;
                else
                {
                    curr = parent;
                    parent = getParent(parent);

                    currentNode = heap[curr];
                    parentNode = heap[parent];
                }
            }
            else
            {
                break;
            }
        }
    }
}
int popHeap(vector<struct node *> &heap)
{
    int n = heap.size();
    struct node *topNode = heap[0];
    int index = topNode->index;
    heap[0] = heap[n - 1];

    vector<struct node *>::iterator itr = heap.begin() + (n - 1);
    heap.erase(itr);
    int c1, c2;
    struct node *c1Node;
    struct node *c2Node;
    struct node *currentNode;
    int curr = 0;
    n -= 1;
    for (; getRightChild(curr) < n;)
    {
        c1 = getLeftChild(curr);
        c2 = getRightChild(curr);
        currentNode = heap[curr];
        c1Node = heap[c1];
        c2Node = heap[c2];
        if (currentNode->diff < c1Node->diff && currentNode->diff < c2Node->diff)
        {
            if (c1Node->diff > c2Node->diff)
            {
                int temp = curr;
                struct node *tempNode = heap[temp];
                heap[curr] = heap[c1];
                heap[c1] = tempNode;
                curr = c1;
            }
            else
            {
                int temp = curr;
                struct node *tempNode = heap[temp];
                heap[curr] = heap[c2];
                heap[c2] = tempNode;
                curr = c2;
            }
        }
        else if (currentNode->diff < c1Node->diff)
        {
            int temp = curr;
            struct node *tempNode = heap[temp];
            heap[curr] = heap[c1];
            heap[c1] = tempNode;
            curr = c1;
        }
        else if (currentNode->diff < c2Node->diff)
        {
            int temp = curr;
            struct node *tempNode = heap[temp];
            heap[curr] = heap[c2];
            heap[c2] = tempNode;
            curr = c2;
        }
        else
        {
            break;
        }
    }
    return index;
}
//16ms
int solveUsingHeap(vector<vector<int>> &costs, vector<struct node *> &heap)
{
    buildMaxHeap(costs, costs.size(), heap); //o(nlogn)
    int n = costs.size();
    int sum = 0;
    for (int i = 0; i < n; i++) //o(n)
    {
        int index = popHeap(heap); //o(logn)
        cout << "index " << index << "\n\n";
        vector<int> v = costs[index];

        if (i < n / 2)
        {
            sum += v[0];
        }
        else
        {
            sum += v[1];
        }
    }
    return sum;
}
void fun(int a, int b)
{
    int a, b, c;
    cout << 5 << endl;
}
int main()
{
    //vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    // vector<vector<int>> costs = {{10, 20}, {30, 200}};
    //vector<vector<int>> costs = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
    //vector<vector<int>> costs = {{945, 563}, {598, 753}, {558, 341}, {372, 54}, {39, 522}, {249, 459}, {536, 264}, {491, 125}, {367, 118}, {34, 665}, {472, 410}, {109, 995}, {147, 436}, {814, 112}, {45, 545}, {561, 308}, {491, 504}, {113, 548}, {626, 104}, {556, 206}, {538, 592}, {250, 460}, {718, 134}, {809, 221}, {893, 641}, {404, 964}, {980, 751}, {111, 935}};
    vector<vector<int>> costs = {{518, 518}, {71, 971}, {121, 862}, {967, 607}, {138, 754}, {513, 337}, {499, 873}, {337, 387}, {647, 917}, {76, 417}};
    // twoCityScheduledCosts(costs, 0, 0, costs.size() / 2, 0, 0);
    // cout << endl;
    // cout << globalSum << endl;
    // cout << solveUsingSort(costs);
    vector<struct node *> heap(costs.size());
    int sum = solveUsingHeap(costs, heap);
    cout << "sum = " << sum;
}
