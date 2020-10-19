/*

Given an array of integers nums and an integer limit, return the size of the longest  non-empty 
subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {

        const int N = nums.size();

        int ans = 0;

        deque<int> big;
        deque<int> small;

        int left = 0;

        for (int right = 0; right < N; right++)
        {
            while (!small.empty() && nums[small.back()] >= nums[right])
            {
                small.pop_back(); // remove the previous greater elements presenr
            }
            small.push_back(right);

            while (!big.empty() && nums[big.back()] <= nums[right])
            {
                big.pop_back(); // remove the previous smaller index
            }
            big.push_back(right);

            int l = nums[big.front()] - nums[small.front()];

            while (l > limit && left < N)
            {
                if (!small.empty() && small.front() <= left) // checking if the left element is the small element
                    small.pop_front();

                // smilatrly check whether left element is the max element
                if (!big.empty() && big.front() <= left)
                    big.pop_front();

                left += 1;

                l = nums[big.front()] - nums[small.front()];
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};