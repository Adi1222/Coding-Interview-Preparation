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
    /********** MY  BOTTOM UP APPROACH ************/

    vector<int> dp, visited;

    int ways(vector<int> &nums, int sum, int &target)
    {
        if (sum < 0)
            return -1;

        if (sum == 0)
            return 1;

        int &ans = dp[sum];
        if (visited[sum])
            return ans;

        visited[sum] = 1;

        ans = 0;

        for (int i = 0; i < nums.size(); i++) // Depth is approached first
        {
            if (nums[i] <= target)
            {
                int temp = ways(nums, sum - nums[i], target);

                if (temp > 0)
                    ans = ans + temp;
            }
        }

        return ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {

        const int N = nums.size();
        dp.resize(target + 1, 0);
        visited.resize(target + 1, 0);

        return ways(nums, target, target);
    }
};