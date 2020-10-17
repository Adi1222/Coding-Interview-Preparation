#include <iostream>
#include <__msvc_all_public_headers.hpp>
using namespace std;
#define int long long
int n, a[100005];
int dp[100005], visited[100005];

int solve(int pos)
{
    if (pos == (n - 1))
        return 0;
    if (pos >= n)
        return INT_MAX;

    int &ans = dp[pos];
    if (visited[pos])
        return dp[pos];
    visited[pos] = 1;

    ans = INT_MAX;
    int left = abs(a[pos] - a[pos + 1]) + solve(pos + 1);
    int right = INT_MAX;
    if (pos + 2 < n)
    {
        right = abs(a[pos] - a[pos + 2]) + solve(pos + 2);
    }

    ans = min({ans, left, right});

    return ans;
}

int32_t main()
{

    cin >> n;

    memset(dp, -1, sizeof dp);
    memset(visited, 0, sizeof visited);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(0);
}