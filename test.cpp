#include <bits/stdc++.h>
#include <vector>
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
void findWordsInBoggleUtil(struct TrieNode *currentNode, string str, vector<vector<char>> &boggle, int n, int m, int x, int y, vector<string> &result)
{

    char ch = boggle[x][y];
    if (ch == '$' || x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    int index = ch - 'A';
    if (ch != '$' && currentNode && currentNode->children[index] != NULL)
    {
        boggle[x][y] = '$';
        str += ch;
        currentNode = currentNode->children[index];
        if (currentNode->isEndOfWord == true)
        {
            result.push_back(str);
            currentNode->isEndOfWord = false;
        }
        if (y + 1 < m)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x, y + 1, result); //go right
        if (y - 1 >= 0)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x, y - 1, result); //go left
        if (x - 1 >= 0)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x - 1, y, result); //go top
        if (x + 1 < n)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x + 1, y, result); //go bottom
        if (x - 1 >= 0 && y - 1 >= 0)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x - 1, y - 1, result); //go top left
        if (x - 1 >= 0 && y + 1 < m)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x - 1, y + 1, result); //go top right
        if (x + 1 < n && y - 1 >= 0)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x + 1, y - 1, result); //go bottom left
        if (x + 1 < n && y + 1 < m)
            findWordsInBoggleUtil(currentNode, str, boggle, n, m, x + 1, y + 1, result); //go bottom right
        boggle[x][y] = ch;
    }
}
vector<string> findWordsInBoggle(struct TrieNode *currentNode, vector<vector<char>> &boggle, int n, int m)
{
    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < boggle[i].size(); j++)
        {
            char ch = boggle[i][j];
            int index = ch - 'A';
            if (root && root->children[index] != NULL)
            {
                string str = "";
                findWordsInBoggleUtil(root, str, boggle, n, m, i, j, result);
            }
        }
    }
    return result;
}
vector<string> findWords(vector<vector<char>> &board, int n, int m)
{
    vector<string> result = findWordsInBoggle(root, board, n, m);
    root = NULL;
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        --t;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            string str;
            cin >> str;
            insertIntoTrie(str);
        }
        int n, m;
        cin >> n;
        cin >> m;
        vector<vector<char>> board(n + 2, vector<char>(m + 2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        }
        vector<string> wordList = findWords(board, n, m);
        for (string str : wordList)
        {
            cout << str << " ";
        }
        cout << "\n";
    }
}