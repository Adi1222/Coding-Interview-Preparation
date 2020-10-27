/*
    Aditya Chavan [{.}]  

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
        }
    }

    cout << dp[n][W] << " " << endl;

    return 0;
}