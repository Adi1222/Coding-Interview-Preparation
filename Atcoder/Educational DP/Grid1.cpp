/*
    Aditya Chavan [{.}]

*/

#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod ((int)(1e9 + 7))
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;

    cin >> h >> w;

    vector<vector<char>> grid;
    grid.resize(h + 1, vector<char>(w + 1));

    vector<vector<int>> dp;
    dp.resize(h + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = 1;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (grid[i][j] != '#')
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }

    cout << dp[h][w] << " " << endl;

    return 0;
}
