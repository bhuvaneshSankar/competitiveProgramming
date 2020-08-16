#include <bits/stdc++.h>
#include <vector>

#include <algorithm>

using namespace std;
int main()
{
    vector<int> v = {3, 5, 3, 3, 2, 4, 2, 4, 5, 1, 1, 5};
    map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << "  " << itr->second << "\n";
    }
}