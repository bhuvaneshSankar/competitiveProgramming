/*
There are N words in a dictionary such that each word is of fixed length and M consists only of lowercase English letters, that is ('a', 'b', ...,'z')
A query word is denoted by Q. The length of query word is M. These words contain lowercase English letters but at some places instead of a letter between 'a', 'b', ...,'z' there is '?'. Refer to the Sample input section to understand this case.

A match count of Q, denoted by match_count(Q) is the count of words that are in the dictionary and contain the same English letters(excluding a letter that can be in the position of ?) in the same position as the letters are there in the query word Q. In other words, a word in the dictionary can contain any letters at the position of '?' but the remaining alphabets must match with the query word.


You are given a query word Q and you are required to compute match_count.

*/

#include <bits/stdc++.h>
#define ALPHA_SIZE 26
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    struct TrieNode *children[ALPHA_SIZE];
};

struct TrieNode *getNode()
{
    struct TrieNode *newnode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    newnode->isEndOfWord = false;
    for (int i = 0; i < ALPHA_SIZE; ++i)
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}
struct TrieNode *root = getNode();
void insert(struct TrieNode *root, string str)
{
    struct TrieNode *curr = root;
    for (int i = 0; i < str.length(); ++i)
    {
        int index = str[i] - 'a';
        if (!curr->children[index])
        {
            curr->children[index] = getNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

int getMatch(struct TrieNode *curr, string pattern, int pos)
{
    if (pos == pattern.length())
    {
        if (curr->isEndOfWord)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (curr == NULL)
    {
        return 0;
    }
    int index = pattern[pos] - 'a';
    int gc = 0;
    if (pattern[pos] == '?')
    {
        for (int i = 0; i < ALPHA_SIZE; ++i)
        {
            if (curr->children[i])
            {
                int count = getMatch(curr->children[i], pattern, pos + 1);
                gc += count;
            }
        }
    }
    else
    {
        if (curr->children[index])
        {
            gc = getMatch(curr->children[index], pattern, pos + 1);
        }
    }
    return gc;
}
int main()
{
    vector<string> dictionary = {"cat", "map", "bat", "pen", "man"};
    for (string str : dictionary)
    {
        insert(root, str);
    }
    //string pattern = "?a?";
    string pattern = "??n";
    // string pattern = "ma?";
    // string pattern = "?at";
    int count = getMatch(root, pattern, 0);
    cout << count;
}