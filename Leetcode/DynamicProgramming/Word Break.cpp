class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        // dp[i]

        int n = s.length();

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;

        unordered_set<string> mp;
        for (string &s : wordDict)
        {
            mp.insert(s);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            string temp;
            for (int j = i; j < n; j++)
            {
                temp.push_back(s[j]);

                if (mp.find(temp) != mp.end())
                {
                    if (dp[j + 1] == 1)
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        for (int i : dp)
            cout << i << " ";

        return dp[0];
    }
};