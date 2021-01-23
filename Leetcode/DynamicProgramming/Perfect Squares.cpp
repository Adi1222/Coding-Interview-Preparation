class Solution
{
public:
    int numSquares(int n)
    {

        /*****************  Intuition & Explanation *****************/

        // n - j^2 upto 0 (we have to reach zero)
        // j^2 <= n

        // dp[i] = min no. of numbers that we need to subtract from n to reach 0
        // base case dp[0] = 0;

        // required ans dp[n]

        //dp[i] = 1 + dp[i - j^2]  among all possible values of that i.e j^ <= i

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Bottom Up Approach

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};