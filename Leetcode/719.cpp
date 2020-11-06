class Solution
{
public:
    bool isPossible(vector<int> &a, int mid, int &k)
    {
        int n = a.size();

        int j = 1;
        int tot = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < n && a[j] - a[i] <= mid)
                j += 1;

            j -= 1;

            tot += j - i;
        }

        return (tot >= k);
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int l = 0; // min diff can be 0 if there are two elements with same value in array (we are just assuming diff .... at the end we'll be getting min dist as our ans if we do Binary search on dist)

        int r = nums[n - 1] - nums[0];

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};