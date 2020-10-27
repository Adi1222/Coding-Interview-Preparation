/*
    Aditya Chavan [{.}]  

*/

#include <iostream>
#include <bits/stdc++.h>
#define in long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp;

    //int dp[n  + 1][m + 1] = {0};

    dp.resize(n + 2, vector<int>(m + 2, 0));

    if (s[0] == t[0])
        dp[1][1] = 1;
    else
        dp[1][1] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = s.length();
    int j = t.length();

    string ans = "";

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            //ans.push_back(s[i - 1]);
            ans = s[i - 1] + ans;
            i -= 1;
            j -= 1;
        }
        else if (dp[i][j - 1] == dp[i][j])
        {
            j -= 1;
        }
        else // dp[i - 1][j] == dp[i][j]
        {
            i -= 1;
        }
    }

    cout << ans << " " << endl;

    return 0;
}