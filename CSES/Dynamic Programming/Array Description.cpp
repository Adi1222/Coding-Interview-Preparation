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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp;
    dp.resize(n, vector<int>(m + 1, 0)); // b'coz allowed integers are between 1 and m

    int x0;
    cin >> x0;

    if (x0 == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][x0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1 && k <= m)
                    {
                        (dp[i][j] += dp[i - 1][k]) %= mod;
                    }
                }
            }
        }
        else
        {
            for (int k : {x - 1, x, x + 1})
            {
                if (k >= 1 && k <= m)
                {
                    (dp[i][x] += dp[i - 1][k]) %= mod;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        (ans += dp[n - 1][i]) %= mod;
    }

    cout << ans << " " << endl;
    return 0;
}