#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define foi(i, n) for (int i = 0; i < n; i++)
#define foj(j, n) for (int j = 0; j < n; j++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define vi vector<int>
#define itriv vector<int>::iterator
#define nl "\n"

using namespace std;
bool found = false;
void util(vector<vector<char>> board, vector<vector<bool>> vis, int m, int n, string word, int len, int curr, int x, int y)
{

    if (curr == len)
    {
        found = true;
        return;
    }
    if (x >= m || x < 0)
    {
        return;
    }
    if (y >= n || y < 0)
    {
        return;
    }
    cout << x << " " << y << " " << curr << " " << word[curr] << nl;
    vis[x][y] = true;
    if (board[x][y] == word[curr])
    {
        if (found == false && x + 1 < m && board[x + 1][y] == word[curr + 1] && vis[x + 1][y] == false)
        {
            util(board, vis, m, n, word, len, curr + 1, x + 1, y);
        }
        if (found == false && x - 1 >= 0 && board[x - 1][y] == word[curr + 1] && vis[x - 1][y] == false)
        {
            util(board, vis, m, n, word, len, curr + 1, x - 1, y);
        }
        if (found == false && y + 1 < n && board[x][y + 1] == word[curr + 1] && vis[x][y + 1] == false)
        {
            util(board, vis, m, n, word, len, curr + 1, x, y + 1);
        }
        if (found == false && y - 1 >= 0 && board[x][y - 1] == word[curr + 1] && vis[x][y - 1] == false)
        {
            util(board, vis, m, n, word, len, curr + 1, x, y - 1);
            ;
        }
    }
    curr = 0;
    if (found == false && x + 1 < m && board[x + 1][y] == word[curr + 1] && vis[x + 1][y] == false)
    {
        util(board, vis, m, n, word, len, curr, x + 1, y);
    }
    if (found == false && x - 1 >= 0 && board[x - 1][y] == word[curr + 1] && vis[x - 1][y] == false)
    {
        util(board, vis, m, n, word, len, curr, x - 1, y);
    }
    if (found == false && y + 1 < n && board[x][y + 1] == word[curr + 1] && vis[x][y + 1] == false)
    {
        util(board, vis, m, n, word, len, curr, x, y + 1);
    }
    if (found == false && y - 1 >= 0 && board[x][y - 1] == word[curr + 1] && vis[x][y - 1] == false)
    {
        util(board, vis, m, n, word, len, curr, x, y - 1);
        }
    vis[x][y] = false;
}
bool exist(vector<vector<char>> &board, string word)
{
    found = false;

    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> vis(m);
    foi(i, m)
    {
        vector<bool> ve(n);
        foj(j, n)
        {
            ve[j] = false;
            cout << board[i][j] << " ";
        }
        vis[i] = ve;
        cout << nl;
    }
    util(board, vis, m, n, word, word.size(), 0, 0, 0);
    return found;
}
void solve()
{
    // int m, n;
    // cin >> m >> n;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    // foi(i, m)
    // {
    //     foj(j, n)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    if (exist(board, word) == true)
    {
        cout << "yes" << nl;
    }
    else
    {
        cout << "no" << nl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //    cin >> t;
    while (t > 0)
    {
        --t;
        solve();
    }
}