/*
    Aditya Chavan
*/

// T.c O( n * (sum/2))

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {

        int n = stones.size();

        int tot = 0;
        for (int s : stones)
            tot += s;

        int s = tot / 2;

        bool dp[n + 1][s + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (stones[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        /* for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= s; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int temp = 0;

        for (int i = 1; i <= s; i++)
        {
            if (dp[n][i])
                temp = max(temp, i);
        }

        cout << temp << " ";

        return tot - 2 * temp;
    }
};