#include <iostream>
using namespace std;

//(2^n)*n
void solve(int arr[], int n)
{

    for (int mask = 0; mask < (1 << n); mask++) //2^n
    {
        long long sumOfSubset = 0;
        for (int i = 0; i < n; i++) //n
        {
            if (mask & (1 << i))
            {
                sumOfSubset += arr[i];
            }
        }
    }
}
int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 7, 5};
    solve(arr, n);
}