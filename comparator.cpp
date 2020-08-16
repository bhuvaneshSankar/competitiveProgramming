#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int comp(int a, int b)
{
    cout << a << " " << b << "\n";
    return a < b;
}
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    vector<int> a = {2, 1, 8, 4, 0, 18, 98, 3};
    sort(a.begin(), a.end(), comp);
    print(a);
}