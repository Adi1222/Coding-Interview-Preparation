/*Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 */

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        const int N = arr.size();

        vector<int> dp(N, 0);
        dp[0] = arr[0];
        int max_ele = arr[0];

        for (int i = 1; i < k; i++)
        {
            max_ele = max(max_ele, arr[i]);
            dp[i] = (i + 1) * max_ele;
        }

        for (int i = k; i < N; i++)
        {
            max_ele = arr[i];

            for (int j = 1; j <= k; j++) // checking for the k times
            {
                max_ele = max(max_ele, arr[i - j + 1]);
                dp[i] = max(dp[i], max_ele * j + dp[i - j]);
            }
        }

        return dp[N - 1];
    }
};