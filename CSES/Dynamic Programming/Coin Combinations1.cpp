#include <iostream>
#include <vector>
#define mod 1000000007
#define int long long int
using namespace std;

int n, x;
vector<int> coins;
vector<int> dp, vis;

/************** BOTTOM UP  APPROACH ************/

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    coins.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp.resize(x + 1, 0);
    vis.resize(x + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] += dp[i - coin];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[x] << " " << endl;

    return 0;
}