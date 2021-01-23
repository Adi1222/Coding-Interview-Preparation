class Solution
{
public:
    // now memoize
    vector<int> dp;
    int solve(int ind, vector<int> &days, vector<int> &costs)
    {
        // base case
        if (ind >= days.size())
            return 0;

        if (dp[ind] != INT_MAX)
            return dp[ind];

        int oneday = costs[0] + solve(ind + 1, days, costs);

        int i;

        for (i = ind; i < days.size(); i++)
        {
            if (days[i] >= days[ind] + 7)
                break;
        }

        int sevendays = costs[1] + solve(i, days, costs);

        for (i = ind; i < days.size(); i++)
        {
            if (days[i] >= days[ind] + 30)
                break;
        }

        int thirtydays = costs[2] + solve(i, days, costs);

        return dp[ind] = min({oneday, sevendays, thirtydays});
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        dp.resize(days.size() + 1, INT_MAX);
        return solve(0, days, costs);
    }
};