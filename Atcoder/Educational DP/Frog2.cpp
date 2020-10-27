/*
    Aditya Chavan [{.}]  

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define hell 1000000007
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
#define take(a, b, c)       \
    for (b = 0; b < c; b++) \
        scanf("%d", &a[b]);

vector<int> dp(100005), vis(100005), arr(100005);
int n, k;

int solve(int pos)
{
    if (pos == n)
        return 0;

    if (pos > n)
        return INT_MAX;

    int &ans = dp[pos];

    if (vis[pos])
        return ans;

    vis[pos] = 1;

    ans = INT_MAX;
    for (int i = pos + 1; i <= min(pos + k, n); i++)
    {

        ans = min(ans, abs(arr[pos] - arr[i]) + solve(i));
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    dp.resize(n + 1, -1);
    vis.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(1) << " " << endl;

    return 0;
}