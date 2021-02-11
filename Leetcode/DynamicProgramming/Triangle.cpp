/*
    Aditya Chavan
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int r = triangle.size();
        int c = triangle[r - 1].size();

        int dp[r + 1][c + 1];

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j > 0 && j < triangle[i].size() - 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];

                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];

                else
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < c; i++)
        {
            ans = min(ans, dp[r - 1][i]);
        }

        return ans;
    }
};