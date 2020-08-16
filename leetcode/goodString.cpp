#include <bits/stdc++.h>
using namspace std;
bool isGood(char c1, char c2)
{
    if (c2 >= 65 && c2 <= 90)
    {
        c2 = tolower(c2);
        if (c1 == c2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (c1 >= 65 && c1 <= 90)
    {
        c1 = tolower(c1);
        if (c1 == c2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    else
    {
        return true;
    }
}
string makeGood(string s)
{
    int prevGood = 0;
    vector<bool> arr(s.length(), true);
    for (int i = 0; i < s.length(); i++)
    {
        cout << "prevGood " << prevGood << " " << i << "\n";
        if (i > 0 && prevGood >= 0)
        {
            cout << prevGood << " " << i << "\n";
            if (!isGood(s[prevGood], s[i]))
            {
                arr[prevGood] = false;
                arr[i] = false;

                prevGood--;
                while (prevGood >= 0 && arr[prevGood] == false)
                {
                    prevGood--;
                }
                continue;
            }
        }
        if (i < s.length() - 1)
        {
            if (!isGood(s[i], s[i + 1]))
            {
                arr[i] = false;
                arr[i + 1] = false;
                i++;
            }
            else
            {
                prevGood = i;
            }
        }
    }
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[i] == true)
        {
            str += s[i];
        }
    }
    return str;
}

/*optimized soln
    string makeGood(string s) {
        string result;
        for(char ch : s){
            
            if(result.size() && (result.back()-'a' == ch-'A' || result.back()-'A' == ch-'a')){
                result.pop_back();
            }
            else{
                result += ch;
            }
        }
        return result;
    }
    */

/*
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:

Input: s = "s"
Output: "s"

*/