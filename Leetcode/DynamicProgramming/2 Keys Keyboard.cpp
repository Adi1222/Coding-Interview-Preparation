class Solution
{
public:
    int vis[1001][1001];
    int dp[1001][1001];
    // memoize

    int solve(int i, int j, int n)
    {
        if (i == n)
            return 0;

        if (i > n)
            return 11111;

        if (vis[i][j] != 0)
        {
            if (dp[i][j] != -1)
                return dp[i][j];
            else
                return 1111; // return some big value
        }

        vis[i][j] = 1;

        // copy option
        int opt1 = 1 + solve(i, i, n);

        // paste option
        int opt2 = 1 + solve(i + j, j, n);

        return dp[i][j] = min(opt1, opt2);
    }

    int minSteps(int n)
    {

        memset(vis, 0, sizeof(dp));
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n);
    }
};