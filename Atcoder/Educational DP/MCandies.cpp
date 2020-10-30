#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define MOD ((int)(1e9 + 7))
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k; // n --> number of children and k --> number of candies

    cin >> n >> k;

    vector<int> a(n + 1); // b'coz 1 based indexing

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(k + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> prefix(k + 1);
        prefix[0] = 1;

        for (int j = 0; j <= k; j++)
        {
            for (int j = 1; j <= k; j++)
            {
                prefix[j] = (prefix[j - 1] % MOD + dp[i][j] % MOD) % MOD;
            }

            if (a[j] >= j)
            {
                dp[i][j] = prefix[j] % MOD;
            }
            else
            {
                int toRemove = j - a[j] - 1;
                dp[i][j] = (prefix[j] % MOD - prefix[toRemove] % MOD + MOD) % MOD; // the differennce can be negative also so add Mod then take mod
            }
        }

        prefix.clear();
    }

    cout << dp[n][k] << " " << endl;

    return 0;
}