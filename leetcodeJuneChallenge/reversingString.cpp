//Day 4
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;
void reverseString(vector<char> &str)
{
    for (int i = 0, j = str.size() - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    for (char ch : str)
    {
        cout << ch;
    }
    cout << endl;
}

int main()
{
    //  vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    vector<char> str = {'h', 'a', 'i'};
    reverseString(str);
}