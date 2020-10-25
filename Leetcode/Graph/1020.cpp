/*

1020. Number of Enclaves
Medium

Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

*/

class Solution
{
public:
    int r, c;

    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || A[i][j] == 0)
            return;

        A[i][j] = 0;
        dfs(A, i + 1, j);
        dfs(A, i - 1, j);
        dfs(A, i, j + 1);
        dfs(A, i, j - 1);
    }

    int numEnclaves(vector<vector<int>> &A)
    {

        r = A.size();
        c = A[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
                {
                    dfs(A, i, j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (A[i][j] == 1)
                    ans += 1;
            }
        }

        return ans;
    }
};