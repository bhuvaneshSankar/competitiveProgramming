#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long

//codeforce 808D
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 3, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1)
    {
        cout << "NO\n";
        return 0;
    }
    ll sumdash = 0;
    unordered_map<ll, int> m1, m2;
    m1[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        m2[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        sumdash += arr[i];
        if (sumdash == sum / 2)
        {
            cout << "YES\n";
            return 0;
        }
        else if (sumdash < sum / 2)
        {
            ll diff = sum / 2 - sumdash;
            if (m2[diff] > 0)
            {
                cout << "YES\n";
                return 0;
            }
        }
        else
        {
            ll diff = sumdash - sum / 2;
            if (m1[diff] > 0)
            {
                cout << "YES\n";
                return 0;
            }
        }
        m1[arr[i + 1]]++;
        m2[arr[i + 1]]--;
    }
    cout << "NO\n";
    return 0;
}
