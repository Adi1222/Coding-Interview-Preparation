#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll dp[100005];

ll solve(int *arr, int n, int ind)
{
    if (ind == n - 1)
    {
        return 1;
    }
    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    ll ans = 0;

    for (int steps = 1; steps <= arr[ind]; steps++)
    {
        ans += solve(arr, n, steps + ind);
        ans = ans % MOD;
    }

    return dp[ind] = ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = -1;
    }

    cout << solve(arr, n, 0);
    return 0;
}