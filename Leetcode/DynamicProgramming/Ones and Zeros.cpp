/*
    Aditya Chavan
*/

class Solution
{
public:
    int dp[610][110][110];

    int solve(vector<string> &strs, int pos, int m, int n)
    {
        if (pos >= strs.size())
            return 0;

        if (m < 0 || n < 0)
            return INT_MIN;

        if (dp[pos][m][n] != -1)
            return dp[pos][m][n];

        int ones = 0, zeros = 0;

        for (char c : strs[pos])
        {
            if (c == '1')
                ones += 1;
            else
                zeros += 1;
        }

        if (m - zeros < 0 || n - ones < 0) // we'll not consider that pos
            return dp[pos][m][n] = solve(strs, pos + 1, m, n);

        // other wise we'll have 2 options :
        // a) either consider that posider string
        // b) or do not consider that position string

        int incl = 1 + solve(strs, pos + 1, m - zeros, n - ones);
        int excl = solve(strs, pos + 1, m, n);

        return dp[pos][m][n] = max(incl, excl);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {

        memset(dp, -1, sizeof(dp));

        return solve(strs, 0, m, n);
    }
};