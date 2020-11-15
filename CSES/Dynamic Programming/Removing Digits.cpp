#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int
using namespace std;

// dp[i] is the minimum number of steps  to go from i to 0

// T C: 0(n * length(n))  ---> O(n)

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }

    cout << dp[n] << " " << endl;

    return 0;
}