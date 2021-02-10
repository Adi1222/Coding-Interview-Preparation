/*
    Aditya Chavan.

*/

// T.C O(m*n)

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp;

        dp.resize(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int x = matrix[0][i] - '0';

            dp[0][i] = x;

            ans = max(ans, dp[0][i]);
        }

        for (int i = 0; i < m; i++)
        {
            int y = matrix[i][0] - '0';
            dp[i][0] = y;
            ans = max(ans, dp[i][0]);
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    continue;
                else
                {
                    int temp = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    dp[i][j] = temp + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans * ans;
    }
};