class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        const int n = nums.size();

        int last = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= last)
                last = i;
        }

        return (last == 0);
    }
};