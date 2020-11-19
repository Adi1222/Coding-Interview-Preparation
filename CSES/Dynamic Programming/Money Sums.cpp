#include <iostream>
#include <vector>
#define mod 1000000007
#define int long long int
using namespace std;

/********     Similar to     0/1 Knapsack    ***********/

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> coins;
    coins.resize(n);

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int max_sum = n * 1000;

    int cnt = 0;

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(max_sum + 1, 0));

    dp[0][0] = 1; // b'coz for sum 0 it is possible i.e empty array

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_sum; j++)
        {
            // now we have have 2 options
            // either consider that coin
            // or don't consider that coin

            dp[i][j] = dp[i - 1][j];

            if (coins[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - coins[i - 1]]); // max will be bwteen (0, 1)
            }
        }
    }

    for (int i = 1; i <= max_sum; i++)
    {
        if (dp[n][i])
        {
            cnt += 1;
            ans.push_back(i);
        }
    }

    cout << cnt << " " << endl;

    for (int s : ans)
    {
        cout << s << " ";
    }

    return 0;
}