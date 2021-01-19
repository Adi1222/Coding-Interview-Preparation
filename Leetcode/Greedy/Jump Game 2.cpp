class Solution
{
public:
    int jump(vector<int> &nums)
    {

        const int n = nums.size();

        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        // dp[i] ---> min steps required to reach ith index

        for (int i = 0; i < n; i++)
        {
            for (int j = min(n - 1, i + nums[i]); j > i; j--)
            {
                if (dp[j] > dp[i] + 1)
                {
                    dp[j] = dp[i] + 1; // adding 1 step b'coz min no of steps required to reach ith index + 1 ste to reach the jth index
                }
                else
                {
                    break; // i.e dp[j] is already min
                }
            }
        }

        return dp[n - 1];
    }
};