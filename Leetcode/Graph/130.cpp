/*

130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

class Solution
{
public:
    int r, c;

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == 'X' || board[i][j] == '@')
        {
            return;
        }

        board[i][j] = '@';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);

        return;
    }

    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0)
            return;

        r = board.size();
        c = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == '@')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};