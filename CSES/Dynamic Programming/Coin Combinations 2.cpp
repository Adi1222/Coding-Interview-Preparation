#include <iostream>
#include <vector>
#define mod 1000000007
#define int long long int
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    vector<int> coins;

    cin >> n >> x;
    coins.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(x + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j]; // if we do not consider the current coin

            if (coins[i - 1] <= j)
            {
                (dp[i][j] += dp[i][j - coins[i - 1]]) %= mod;
            }
        }
    }

    cout << dp[n][x] << " " << endl;

    return 0;
}