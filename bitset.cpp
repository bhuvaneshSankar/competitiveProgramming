#include <bits/stdc++.h>
using namespace std;
#define N 32

int main()
{
    bitset<N> bs1[3];
    int arr[3] = {14, 98, 23};
    for (int i = 0; i < 3; i++)
    {
        bs1[i] = arr[i];
        cout << bs1[i] << endl;
    }
    cout << (bs1[0] & bs1[1]).count();
}