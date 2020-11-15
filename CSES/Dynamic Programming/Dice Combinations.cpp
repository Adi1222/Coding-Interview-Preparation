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

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // one way with sum zero i.e the empty set

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] % mod << " " << endl;

    return 0;
}