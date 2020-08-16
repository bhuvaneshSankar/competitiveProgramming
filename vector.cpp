#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool compFunc(int i, int j)
{
    return i > j;
}
void nestedVectors()
{
    vector<vector<int>> vec = {{1, 2}, {3, 4}, {5, 6}};
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    nestedVectors();
    // vector<int> vec = {12, 8, 102, 53, 1, 89};

    // printVector(vec);

    // sort(vec.begin(), vec.end()); //o(NlogN)
    // printVector(vec);

    // cout << binary_search(vec.begin(), vec.end(), 53) << endl; //o(logN)

    // vector<int>::iterator itr = lower_bound(vec.begin(), vec.end(), 89); // returns iterator to >=

    // for (; itr != vec.end(); itr++)
    // {
    //     cout << *itr << " ";
    // }
    // cout << endl;

    // vector<int>::iterator itr2 = upper_bound(vec.begin(), vec.end(), 89); //returns iterator to >

    // for (; itr2 != vec.end(); itr2++)
    // {
    //     cout << *itr2 << " ";
    // }
    // cout << endl;

    // //reverse the vector

    // sort(vec.begin(), vec.end(), compFunc);

    // for (auto itr3 = vec.begin(); itr3 != vec.end(); itr3++)
    // {
    //     cout << *itr3 << " ";
    // }
    // cout << endl;
    // auto it4 = vec.end();
    // cout << "end " << *it4;
}