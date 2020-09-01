#include <bits/stdc++.h>
#include <set>
using namespace std;

/*
 * Complete the 'smallestString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY substrings as parameter.
 */

struct Comp
{
    bool operator()(string a, string b)
    {
        int l1 = a.length();
        int l2 = b.length();
        int i = 0, j = 0;
        while (i < l1 && j < l2 && a[i] == b[j])
        {
            i++;
            j++;
        }
        if (i < l1 && j < l2)
        {
            return a[i] < b[j];
        }
        if (i < l1 && j == l2)
        { //a not yet finished b finished
            return a[i] <= b[0];
        }
        if (j < l2 && i == l1)
        { //b not yet finished a finished
            return b[j] > a[0];
        }
        if (i == j)
        {
            return true;
        }
        return true;
    }
};
bool comp(string a, string b)
{
    int l1 = a.length();
    int l2 = b.length();
    int i = 0, j = 0;
    while (i < l1 && j < l2 && a[i] == b[j])
    {
        i++;
        j++;
    }
    if (i < l1 && j < l2)
    {
        return a[i] < b[j];
    }
    if (i < l1 && j == l2)
    { //a not yet finished b finished
        return a[i] <= b[0];
    }
    if (j < l2 && i == l1)
    { //b not yet finished a finished
        return b[j] > a[0];
    }
    if (i == j)
    {
        return true;
    }
    return true;
}
// string smallestString(vector<string> subs)
// {
//     multiset<string, Comp> ms;
//     for (string s : subs)
//     {
//         ms.insert(s);
//     }
//     string res = "";
//     for (string s : ms)
//     {
//         res += s;
//     }
//     return res;
// }
string smallestString(vector<string> ms)
{
    sort(ms.begin(), ms.end(), comp);
    string res = "";
    for (string s : ms)
    {
        res += s;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<string> vi(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vi[i] = s;
    }
    string s = smallestString(vi);
    cout << s;
}