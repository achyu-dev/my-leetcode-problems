#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }

        // downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        // right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        // upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (grid[0][0] == 1)
            solve(0, 0, grid, n, ans, "", vis);
        return ans;
    }
};

class Solution2
{
public:
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &vis)
    {
        if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && maze[x][y] == 1)
            return true;
        return false;
    }

    void solve(int x, int y, int n, vector<vector<int>> &maze, vector<string> &ans, string path, vector<vector<int>> &vis, int di[], int dj[], string dir)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + di[i];
            int nextY = y + dj[i];
            if (isSafe(nextX, nextY, n, maze, vis))
            {
                vis[x][y] = 1;
                solve(nextX, nextY, n, maze, ans, path + dir[i], vis, di, dj, dir);
                vis[x][y] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        string dir = "DLRU";
        if (maze[0][0] == 1)
            solve(0, 0, n, maze, ans, "", vis, di, dj, dir);
        return ans;
    }
};

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    Solution2 sol;
    vector<string> paths = sol.findPath(maze);
    for (const string &path : paths)
    {
        cout << path << endl;
    }
    return 0;
}