#include <bits/stdc++.h>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
    int perimeter = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (i > 0 && grid[i - 1][j] == 0)
                {
                    perimeter++;
                }
                if (j > 0 && grid[i][j - 1] == 0)
                {
                    perimeter++;
                }
                if (j < grid[i].size() - 1 && grid[i][j + 1] == 0)
                {
                    perimeter++;
                }
                if (i < grid.size() - 1 && grid[i + 1][j] == 0)
                {
                    perimeter++;
                }
                if (i == 0)
                {
                    perimeter++;
                }
                if (j == 0)
                {
                    perimeter++;
                }
                if (i == grid.size() - 1)
                {
                    perimeter++;
                }
                if (j == grid[i].size() - 1)
                {
                    perimeter++;
                }
            }
        }
    }
    return perimeter;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 0, 0},
                             {1, 1, 1, 0},
                             {0, 1, 0, 0},
                             {1, 1, 0, 0}};
    int len = islandPerimeter(v);
    cout << len;
}