#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int
using namespace std;

int n, x;
vector<int> coins;
vector<int> dp, vis;

/************** TOP DOWN APPROACH ************/

int solve(int sum)
{
    // base conditions
    if (sum < 0)
    {
        return -1;
    }

    if (sum == 0)
    {
        return 0;
    }

    int &ans = dp[sum];

    if (vis[sum])
    {
        return ans;
    }

    vis[sum] = 1;

    ans = INT_MAX;

    for (int coin : coins)
    {
        int temp = solve(sum - coin);

        if (temp >= 0 && temp < ans)
        {
            ans = 1 + temp;
        }
    }

    return ans != INT_MAX ? ans : -1;
}

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

    dp.resize(x + 1, INT_MAX);
    vis.resize(x + 1, 0);

    cout << solve(x) << " " << endl;

    return 0;
}