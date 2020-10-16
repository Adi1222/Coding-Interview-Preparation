/* You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S. */

// T C:  O(l * n)

class Solution
{
public:
    vector<vector<int>> dp, visited;

    int ways(vector<int> &nums, int pos, int sum, int &S)
    {
        // nbase case
        if (pos == nums.size())
            return sum == S;

        int &ans = dp[pos][sum + 1000];

        if (visited[pos][sum + 1000])
            return ans;

        visited[pos][sum + 1000] = 1;
        ans = 0;
        ans = ways(nums, pos + 1, sum + nums[pos], S) + ways(nums, pos + 1, sum - nums[pos], S);

        return ans;
    }

    int findTargetSumWays(vector<int> &nums, int S)
    {

        const int N = nums.size();

        if (N == 0)
            return 0;

        // Remember the max val is 1000
        // so we need to make array of size 2000 to include the negative elements also

        dp.resize(N, vector<int>(2001, 0));
        visited.resize(N, vector<int>(2001, 0));

        return ways(nums, 0, 0, S);
    }
};