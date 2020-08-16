#include <bits/stdc++.h>
#include <vector>
#include <set>
#define pb push_back
#define ALPHA_SIZE 26
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    struct TrieNode *children[ALPHA_SIZE];
};
struct TrieNode *root = NULL;

struct TrieNode *getTrieNode()
{
    // struct TrieNode *newnode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    struct TrieNode *newnode = new TrieNode;
    newnode->isEndOfWord = false;
    for (int i = 0; i < ALPHA_SIZE; i++)
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}
void insertIntoTrie(string word)
{
    if (root == NULL)
    {
        root = getTrieNode();
        cout << "isEnd " << root->isEndOfWord << "\n";
    }
    struct TrieNode *currentNode = root;
    for (char ch : word)
    {
        int index = ch - 'A'; //trie consists of uppercase letters
        if (currentNode->children[index] == NULL)
        {
            currentNode->children[index] = getTrieNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = true;
}
bool isWordPresentInTrie(string word, struct TrieNode *currentNode)
{
    if (currentNode == NULL)
        return false;
    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        if (ch == '.')
        {
            for (int j = 0; j < ALPHA_SIZE; j++)
            {
                if (currentNode->children[j] != NULL)
                {
                    bool isSuffixPresent = isWordPresentInTrie(word.substr(i + 1), currentNode->children[j]);
                    if (isSuffixPresent == true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        int index = ch - 'A';
        if (currentNode->children[index] == NULL)
        {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode && currentNode->isEndOfWord;
}

void findWordsInBoggleUtil(struct TrieNode *currentNode, string str, vector<vector<char>> boggle, vector<vector<bool>> &visited, int n, int m, int x, int y, set<string> &result)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    char ch = boggle[x][y];
    int index = ch - 'A';
    if (!visited[x][y] && currentNode->children[index] != NULL)
    {
        str += ch;
        if (currentNode->children[index]->isEndOfWord == true)
        {
            result.insert(str);
        }
        visited[x][y] = true;

        if (currentNode->children[index] != NULL)
        {
            findWordsInBoggleUtil(currentNode->children[index], str, boggle, visited, n, m, x, y + 1, result); //go right
            findWordsInBoggleUtil(currentNode->children[index], str, boggle, visited, n, m, x, y - 1, result); //go left
            findWordsInBoggleUtil(currentNode->children[index], str, boggle, visited, n, m, x - 1, y, result); //go top
            findWordsInBoggleUtil(currentNode->children[index], str, boggle, visited, n, m, x + 1, y, result); //go bottom
        }
        visited[x][y] = false;
    }
}

set<string> findWordsInBoggle(struct TrieNode *currentNode, vector<char> boggle[], int n, int m)
{
    set<string> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < boggle[i].size(); j++)
        {
            char ch = boggle[i][j];
            int index = ch - 'A';
            if (root && root->children[index] != NULL)
            {
                string str;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                cout << "in \n";
                findWordsInBoggleUtil(root, str, boggle, visited, n, m, i, j, result);
            }
        }
    }
    return result;
}
void getAllWordsInTrie(struct TrieNode *currNode, string str, vector<string> &wordList)
{
    if (currNode && currNode->isEndOfWord)
    {
        wordList.push_back(str);
    }
    for (int i = 0; i < ALPHA_SIZE; i++)
    {
        if (currNode->children[i])
        {
            getAllWordsInTrie(currNode->children[i], str + (char)(i + 'A'), wordList);
        }
    }
}
vector<string> getAllWordsInTrieUtil()
{
    vector<string> wordList;
    string str;
    getAllWordsInTrie(root, str, wordList);
    return wordList;
}
/*
int main()
{
    //   vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
    vector<string> dictionary = {"dfd", "ded", "fd", "e", "dec", "df"};
    int n = 4, m = 2;
    vector<char> boggle[n];
    for (int i = 0; i < n; i++)
    {
        vector<char> vc;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            vc.push_back(ch);
        }
        boggle[i] = vc;
    }
    for (int i = 0; i < dictionary.size(); i++)
    {
        cout << dictionary[i] << " ";
        insertIntoTrie(dictionary[i]);
    }

    set<string> result = findWordsInBoggle(root, boggle, n, m);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
*/
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int len;
        cin >> len;
        vector<string> dict(len);
        for (int j = 0; j < len; j++)
        {
            string str;
            cin >> str;
            dict.pb(str);
            insertIntoTrie(str);
        }
        int m, n;
        cin >> m >> n;
        vector<char> boggle[m];
        for (int p = 0; p < m; p++)
        {
            vector<char> vc;
            for (int j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                vc.push_back(ch);
            }
            boggle[p] = vc;
        }
        set<string> wordList = findWordsInBoggle(root, boggle, m, n);
        for (string str : wordList)
        {
            cout << str << " ";
        }
        cout << "\n";
        root = NULL;
    }
    return 0;
}
//G I Z U E K Q S E