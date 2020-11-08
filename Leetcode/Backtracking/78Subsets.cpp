class Solution
{
public:
    vector<vector<int>> ans;

    void combinations(vector<int> &nums, vector<int> cur, int pos)
    {
        if (pos < 0)
        {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[pos]); // consider that element

        combinations(nums, cur, pos - 1);

        cur.pop_back(); // remove the element

        combinations(nums, cur, pos - 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> cur;
        combinations(nums, cur, nums.size() - 1);
        return ans;
    }
};