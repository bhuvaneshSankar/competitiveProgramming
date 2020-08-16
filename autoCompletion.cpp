#include <bits/stdc++.h>
#include <vector>
#define ALPHA_SIZE 26
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    struct TrieNode *children[26];
};

struct TrieNode *getNode()
{
    struct TrieNode *newnode = new TrieNode;
    newnode->isEndOfWord = false;
    for (int i = 0; i < ALPHA_SIZE; i++)
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}

struct TrieNode *root = getNode();

void insert(string word)
{
    struct TrieNode *current = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (!current->children[index])
        {
            current->children[index] = getNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void getAllWords(string str, vector<string> &wordList, struct TrieNode *current)
{
    if (current && current->isEndOfWord)
    {
        wordList.push_back(str);
    }
    for (int i = 0; i < ALPHA_SIZE; i++)
    {
        if (current->children[i])
        {
            char ch = i + 'a';
            getAllWords(str + ch, wordList, current->children[i]);
        }
    }
}

void matchPrefix(string str, string prefix, int pos, vector<string> &wordList, struct TrieNode *current)
{
    if (pos >= prefix.length() && current->isEndOfWord)
    {
        wordList.push_back(str);
    }
    if (pos == prefix.length())
    {
        for (int i = 0; i < ALPHA_SIZE; i++)
        {
            if (current->children[i])
            {
                char ch = i + 'a';
                matchPrefix(str + ch, prefix, pos, wordList, current->children[i]);
            }
        }
    }
    else
    {
        char ch = prefix[pos];
        int index = ch - 'a';
        if (current->children[index])
        {
            matchPrefix(str + ch, prefix, pos + 1, wordList, current->children[index]);
        }
        else
        {
            return;
        }
    }
}
void printWordList(vector<string> wordList)
{
    for (string str : wordList)
    {
        cout << str << " ";
    }
    cout << "\n";
}

vector<string> matchPrefixUtil(string prefix)
{
    vector<string> wordList;
    string str = "";
    matchPrefix(str, prefix, 0, wordList, root);
    return wordList;
}
int main()
{
    char ch;
    do
    {
        cout << "Press 1 for adding a new word\nPress 2 for auto complete\n";
        int flag;
        cin >> flag;
        string str, prefix;
        vector<string> matchedWords;
        switch (flag)
        {
        case 1:
            cout << "Enter the word to add in to the list\n";
            cin >> str;
            insert(str);
            break;
        case 2:
            cout << "Enter the prefix word to auto complete\n";
            cin >> prefix;
            matchedWords = matchPrefixUtil(prefix);
            if (matchedWords.size() == 0)
            {
                cout << "Sorry no match for the word found.\n";
            }
            else
            {
                printWordList(matchedWords);
            }
            matchedWords.clear();
            break;
        default:
            cout << "Valid range is 1 and 2 only.\n";
            break;
        }
        cout << "Press y to continue and any other letter to exist.\n";
        cin >> ch;
    } while (ch == 'y');
}