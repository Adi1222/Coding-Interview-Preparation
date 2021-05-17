class Solution
{
public:
    int longestOnes(vector<int> &arr, int k)
    {

        const int n = arr.size();

        int l = 0, r;

        int cnt = 0;
        int ans = 0;

        for (r = 0; r < n; r++)
        {
            if (arr[r] == 0)
            {
                cnt += 1;
            }

            if (cnt <= k)
            {
                ans = max(ans, r - l + 1);
            }
            else
            {
                while (l < r && cnt > k)
                {
                    if (arr[l] == 0)
                    {
                        cnt -= 1;
                    }

                    l++;

                    if (cnt == k)
                    {
                        ans = max(ans, r - l + 1);
                    }
                }
            }
        }

        return ans;
    }
};