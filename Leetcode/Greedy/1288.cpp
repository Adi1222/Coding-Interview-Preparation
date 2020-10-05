/*
Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals

*/

class Solution
{
public:
    static bool mycom(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0]; // sorting in increasing order
    }

    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), mycom);

        int ans = intervals.size();
        int maxend = 0;

        for (vector<int> currentinterval : intervals)
        {
            if (currentinterval[1] <= maxend)
            {
                ans -= 1;
                // removing the current interval
            }

            maxend = max(currentinterval[1], maxend);
        }

        return ans;
    }
};