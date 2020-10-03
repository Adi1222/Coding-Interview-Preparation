class Solution
{
public:
    int rob(vector<int> &nums)
    {

        const int N = nums.size();

        vector<int> dp1(N + 2);
        vector<int> dp2(N + 2);

        if (N == 1)
            return nums[0];

        for (int i = 0; i <= N - 2; i++)
        {
            dp1[i + 2] = dp1[i + 1];
            dp1[i + 2] = max(dp1[i + 2], nums[i] + dp1[i]);
        }

        for (int i = 1; i <= N - 1; i++)
        {
            dp2[i + 2] = dp2[i + 1];
            dp2[i + 2] = max(dp2[i + 2], nums[i] + dp2[i]);
        }

        return max(dp1[N], dp2[N + 1]);
    }
};