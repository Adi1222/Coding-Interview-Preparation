#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long

using namespace std;

// T.C 0(m*n) -- unbound Knapsack

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n; // m -> floor n -> people

    cin >> m >> n;

    int arr[m];

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - arr[i - 1]]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }

    cout << dp[m][n] << " ";
    return 0;
}