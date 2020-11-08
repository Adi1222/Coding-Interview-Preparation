class Solution
{
public:
    set<vector<int>> st;

    void combinations(vector<int> &nums, vector<int> cur, int pos)
    {
        if (pos < 0)
        {
            st.insert(cur);
            return;
        }

        cur.push_back(nums[pos]);

        combinations(nums, cur, pos - 1);

        cur.pop_back();

        combinations(nums, cur, pos - 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<int> cur;

        sort(nums.begin(), nums.end());

        combinations(nums, cur, nums.size() - 1);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};