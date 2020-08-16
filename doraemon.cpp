#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<pair<int, int>>
#define itriv vector<int>::iterator

using namespace std;

// struct node
// {
//     int people;
//     int count;
// };

// int getParent(int i)
// {
//     return (i - 1) / 2;
// }
// int getLeftChild(int i)
// {
//     return (i * 2) + 1;
// }
// int getRightChild(int i)
// {
//     return (i * 2) + 2;
// }
// void printHeap(vector<struct node *> &heap)
// {
//     for (int i = 0; i < heap.size(); i++)
//     {
//         struct node *current = heap[i];
//         cout << current->people << " " << current->count << "\n";
//     }
//     cout << "\n";
// }
// void buildMaxHeap(map<int, int> people, int n, vector<struct node *> &heap)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int a = i;
//         int b = people[i];
//         struct node *newnode = (struct node *)malloc(sizeof(struct node));
//         newnode->people = i;
//         newnode->count = b;
//         heap[i] = newnode;
//         int parent, leftChild, rightChild;
//         parent = getParent(i);
//         struct node *currentNode = newnode;
//         int curr = i;
//         while (parent >= 0)
//         {
//             struct node *parentNode = heap[parent];
//             if (parentNode->count < currentNode->count || (parentNode->count == currentNode->count && parentNode->people < currentNode->people))
//             {
//                 struct node *temp = parentNode;
//                 heap[parent] = newnode;
//                 heap[curr] = parentNode;
//                 //    printHeap(heap);
//                 if (parent == 0)
//                     break;
//                 else
//                 {
//                     curr = parent;
//                     parent = getParent(parent);

//                     currentNode = heap[curr];
//                     parentNode = heap[parent];
//                 }
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }
// }

// int popHeap(vector<struct node *> &heap)
// {
//     int n = heap.size();
//     struct node *topNode = heap[0];
//     int index = topNode->people;
//     int count = topNode->count;
//     heap[0] = heap[n - 1];

//     vector<struct node *>::iterator itr = heap.begin() + (n - 1);
//     heap.erase(itr);
//     int c1, c2;
//     struct node *c1Node;
//     struct node *c2Node;
//     struct node *currentNode;
//     int curr = 0;
//     n -= 1;
//     for (; getRightChild(curr) < n;)
//     {
//         c1 = getLeftChild(curr);
//         c2 = getRightChild(curr);
//         currentNode = heap[curr];
//         c1Node = heap[c1];
//         c2Node = heap[c2];
//         if (currentNode->count < c1Node->count && currentNode->count < c2Node->count)
//         {
//             if (c1Node->count > c2Node->count)
//             {
//                 int temp = curr;
//                 struct node *tempNode = heap[temp];
//                 heap[curr] = heap[c1];
//                 heap[c1] = tempNode;
//                 curr = c1;
//             }
//             else if (c1Node->count == c2Node->count)
//             {
//                 if (c1Node->people < c2Node->people)
//                 {
//                     int temp = curr;
//                     struct node *tempNode = heap[temp];
//                     heap[curr] = heap[c2];
//                     heap[c2] = tempNode;
//                     curr = c2;
//                 }
//                 else
//                 {
//                     int temp = curr;
//                     struct node *tempNode = heap[temp];
//                     heap[curr] = heap[c1];
//                     heap[c1] = tempNode;
//                     curr = c1;
//                 }
//             }
//             else
//             {
//                 int temp = curr;
//                 struct node *tempNode = heap[temp];
//                 heap[curr] = heap[c2];
//                 heap[c2] = tempNode;
//                 curr = c2;
//             }
//         }
//         else if (currentNode->count < c1Node->count)
//         {
//             int temp = curr;
//             struct node *tempNode = heap[temp];
//             heap[curr] = heap[c1];
//             heap[c1] = tempNode;
//             curr = c1;
//         }
//         else if (currentNode->count < c2Node->count)
//         {
//             int temp = curr;
//             struct node *tempNode = heap[temp];
//             heap[curr] = heap[c2];
//             heap[c2] = tempNode;
//             curr = c2;
//         }
//         else if (currentNode->count == c1Node->count)
//         {
//             if (currentNode->people < c1Node->people)
//             {
//                 int temp = curr;
//                 struct node *tempNode = heap[temp];
//                 heap[curr] = heap[c1];
//                 heap[c1] = tempNode;
//                 curr = c1;
//             }
//         }
//         else if (currentNode->count == c2Node->count)
//         {
//             if (currentNode->people < c2Node->people)
//             {
//                 int temp = curr;
//                 struct node *tempNode = heap[temp];
//                 heap[curr] = heap[c2];
//                 heap[c2] = tempNode;
//                 curr = c2;
//             }
//         }
//         else
//         {
//             break;
//         }
//     }
//     return index;
// }

// int solveUsingHeap(map<int, int> people, int n, int k, vector<struct node *> &heap)
// {
//     buildMaxHeap(people, n, heap); //o(nlogn)
//     for (int i = 0; i < k; i++)    //o(n)
//     {
//         int index = popHeap(heap); //o(logn)
//         cout << index << " ";
//     }
//     cout << "\n";
//     return 1;
// }

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{

    if (a.first > b.first)
    {
        return true;
    }
    return false;
}
bool comp1(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }
    return false;
}
void print(vector<pair<ll, ll>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }
}
void solve()
{
    int n;
    cin >> n;
    unordered_map<ll, ll> shop;
    ll val;
    foi(i, n)
    {
        cin >> val;

        shop[val] += 1;
    }
    cout << "shop size " << shop.size() << "\n";
    ll k;
    cin >> k;
    vector<pair<ll, ll>> va;
    for (ll i = 0; i < 100000; i++)
    {
        ll a = shop[i];
        if (a > 0)
        {
            va.push_back(make_pair(a, i));
        }
    }
    cout << "va size " << va.size() << "\n";
    cout << "b4\n";
    print(va);
    sort(va.begin(), va.end(), comp);
    cout << "first sort\n";
    print(va);
    sort(va.begin(), va.end(), comp1);
    cout << "second sort\n";
    print(va);
    for (ll i = 0; i < k && i < va.size(); i++)
    {
        cout << va[i].second << " ";
    }
    cout << "\n";
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