#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct trieNode
{
    struct trieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct trieNode *root = NULL;

class WordDictionary
{

public:
    /** Initialize your data structure here. */

    WordDictionary()
    {
        root = NULL;
    }
    static struct trieNode *getNode()
    {
        struct trieNode *newnode = new trieNode;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            newnode->children[i] = NULL;
        }
        newnode->isEndOfWord = false;
        return newnode;
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        struct trieNode *currentNode;
        if (root == NULL)
        {
            root = (struct trieNode *)getNode();
            currentNode = root;
        }
        else
        {
            currentNode = root;
        }
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (currentNode->children[index] == NULL)
            {
                currentNode->children[index] = (struct trieNode *)getNode();
            }
            currentNode = currentNode->children[index];
        }
        if (currentNode != NULL)
        {
            currentNode->isEndOfWord = true;
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchUtil(word, root);
    }
    bool searchUtil(string word, struct trieNode *currentNode)
    {
        if (currentNode == NULL)
        {
            return false;
        }
        bool isPresent = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isPresent == true && word[i] == '.')
            {
                return true;
            }
            if (word[i] == '.')
            {
                for (int j = 0; j < ALPHABET_SIZE; j++)
                {
                    if (currentNode->children[j] != NULL)
                    {
                        int newlen = word.length() - i;
                        string newStr = word.substr(i + 1);
                        return searchUtil(newStr, currentNode->children[j]);
                    }
                }
            }
            else
            {
                int index = word[i] - 'a';
                if (currentNode->children[index] == NULL)
                {
                    return false;
                }
                isPresent = true;
                currentNode = currentNode->children[index];
            }
        }
        if (currentNode->isEndOfWord == false || currentNode == NULL)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */