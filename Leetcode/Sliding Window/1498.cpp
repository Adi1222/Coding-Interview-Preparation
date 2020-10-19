/*

Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that 
the sum of the minimum and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

*/

#define mod 1000000007
class Solution
{
public:
    long binaryExponentiation(int x, int y)
    {
        if (y == 1)
            return x;
        if (y == 0)
            return 1;
        if (x == 1)
            return 1;

        long ans = 1;

        if (y % 2 == 0) // for even
        {
            ans = binaryExponentiation(x, y / 2);
            ans *= ans;
        }
        else
        {
            ans = binaryExponentiation(x, y - 1);
            ans *= x;
        }

        return ans % mod;
    }

    int numSubseq(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans += binaryExponentiation(2, right - left);
                ans %= mod;
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }

        return ans;
    }
};