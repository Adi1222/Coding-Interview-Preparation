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

    int n;
    cin >> n;
    vector<vector<char>> grid;
    grid.resize(n, vector<char>(n, '-'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp;
    dp.resize(n, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                if (i > 0)
                    (dp[i][j] += dp[i - 1][j]) %= mod;

                if (j > 0)
                    (dp[i][j] += dp[i][j - 1]) %= mod;
            }
            else
            {
                dp[i][j] = 0; // because there is trap here and zero b'coz we are also gonna add this value further
            }
        }
    }

    cout << dp[n - 1][n - 1] << " " << endl;

    return 0;
}