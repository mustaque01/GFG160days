// C++ Program to find the minimum time
// in which all oranges will get rotten

#include <bits/stdc++.h>
using namespace std;

// Check if i, j is within the array
// limits of row and column
bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int orangesRotting(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // all four directions
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // queue to store cell position
    queue<vector<int>> q;

    // find all rotten oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    // counter of elapsed time
    int elapsedTime = 0;

    while (!q.empty())
    {

        // increase time by 1
        elapsedTime++;

        int len = q.size();
        while (len--)
        {
            vector<int> cur = q.front();
            q.pop();
            int i = cur[0];
            int j = cur[1];

            // change 4-directionally connected cells
            for (auto dir : directions)
            {
                int x = i + dir[0];
                int y = j + dir[1];

                // if cell is in the matrix and
                // the orange is fresh
                if (isSafe(x, y, n, m) && mat[x][y] == 1)
                {
                    mat[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
    }

    // check if any fresh orange is remaining
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return max(0, elapsedTime - 1);
}

int main()
{
    vector<vector<int>> mat = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
    cout << orangesRotting(mat);
    return 0;
}