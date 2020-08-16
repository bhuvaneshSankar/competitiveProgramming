#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> charMap;
    for (char ch : s)
    {
        charMap[ch] += 1;
    }
    int length = 0;
    bool isOddFound = false;
    for (pair<char, int> pr : charMap)
    {
        if (pr.second & 1)
        {
            length += (pr.second - 1);
            isOddFound = true;
        }
        else
        {
            length += pr.second;
        }
    }
    if (isOddFound)
    {
        length += 1;
    }
    return length;
}
