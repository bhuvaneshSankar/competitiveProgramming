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
// int getAns(int curr, int left){
//     if(par[curr] == -1){
//         return -1;
//     }
//     if(left == 1){
//         return par[curr];
//     }
//     return getAns(par[curr], left-1);
// }
int n;
vi par;

vector<vector<int>> arr;
//vector<int> arr[];
void construct(vi parent)
{
    vector<int> v;
    for (int i = 0; i < parent.size(); i++)
    {
        if (i == 0)
        {
            v.push_back(-1);
            //    cout << "size " << v.size();
            arr.push_back(v);
        }
        else
        {
            v = arr[parent[i]];
            v.push_back(parent[i]);
            arr.push_back(v);
        }
    }
}
void print()
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        vi v = arr[i];
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << " ";
        }
        cout << "\n";
    }
}
void util(int a, vector<int> &parent)
{
    n = a;
    par = parent;
    construct(parent);
}

int getKthAncestor(int node, int k)
{
    cout << "get k" << nl;
    vi v = arr[node];
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << nl;
    int flag = n - k;

    if (flag < 1)
    {
        return -1;
    }
    return v[flag];
}
void solve()
{
    int n = 7;
    vector<int> arr = {-1, 0, 0, 1, 1, 2, 2};
    util(n, arr);
    print();
    int res;
    res = getKthAncestor(3, 1);
    deb(res);
    //  getKthAncestor(5, 2);
    //  getKthAncestor(6, 3);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}