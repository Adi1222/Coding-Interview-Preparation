class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {

        const int N = nums.size();

        if (k >= N)
            k = N - 1;

        set<long long> st;

        for (int i = 0; i < N; i++)
        {
            if (i > k)
            {
                st.erase(nums[i - k - 1]); // we no longer need this element as it does not lie n the range of k
            }

            auto it = st.lower_bound((long long)nums[i] - t);

            //.... range will be  [number - t  ....  number   ..... number + t]

            if ((it != st.end()) && (abs(*it - nums[i]) <= t))
            {
                return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};