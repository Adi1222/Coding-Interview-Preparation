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

vector<vector<int>> dp, vis, arr;
int n;

int vacations(int day, int activity)
{
    if (day == n)
    {
        return 0;
    }

    int &ans = dp[day][activity];

    if (vis[day][activity])
        return ans;

    vis[day][activity] = 1;

    ans = INT_MIN;

    if (activity == 0) // that means we are at 0th index and haven't considered any activity
    {
        ans = max(ans, arr[day][1] + vacations(day + 1, 1));
        ans = max(ans, arr[day][2] + vacations(day + 1, 2));
        ans = max(ans, arr[day][3] + vacations(day + 1, 3));
    }

    else if (activity == 1) // we have chosen swimming
    {
        ans = max(ans, arr[day][2] + vacations(day + 1, 2));
        ans = max(ans, arr[day][3] + vacations(day + 1, 3));
    }

    else if (activity == 2) // catch bugs on mountain
    {
        ans = max(ans, arr[day][1] + vacations(day + 1, 1));
        ans = max(ans, arr[day][3] + vacations(day + 1, 3));
    }

    else // do your homework
    {
        ans = max(ans, arr[day][1] + vacations(day + 1, 1));
        ans = max(ans, arr[day][2] + vacations(day + 1, 2));
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dp.resize(n, vector<int>(4, -1));
    vis.resize(n, vector<int>(4, 0));
    arr.resize(n, vector<int>(4));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << vacations(0, 0) << " " << endl;

    return 0;
}