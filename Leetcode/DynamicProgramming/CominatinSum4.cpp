/*

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

*/

class Solution
{
public:
    vector<unsigned long long int> dp, visited;

    int combinationSum4(vector<int> &nums, int target)
    {

        const int N = nums.size();
        dp.resize(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (nums[j] <= i)
                {
                    dp[i] = dp[i] + dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};