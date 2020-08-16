#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
*/

void bfs(vector<vector<int>> &grid, int n, int m, queue<pair<int, int>> &q, int count, int &level, int &fresh)
{
    int lc = 0;
    while (!q.empty() && count > 0)
    {
        count--;
        pair<int, int> pr = q.front();
        q.pop();
        int trav[5] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = pr.first + trav[i];
            int ny = pr.second + trav[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
            {
                continue;
            }
            lc++;
            fresh--;
            grid[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    if (q.empty() && lc == 0)
    {
        return;
    }
    bfs(grid, n, m, q, lc, ++level, fresh);
}
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                count++;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    int level = 0;
    bfs(grid, n, m, q, count, level, fresh);
    return fresh == 0 ? level : -1;
}
