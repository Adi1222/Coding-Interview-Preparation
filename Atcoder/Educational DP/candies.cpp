/*
    Aditya Chavan [{.}]  

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod ((int)(1e9 + 7))

vector<vector<int>> dp, vis;
vector<int> a;
int n, k;

int ways(int pos, int s)
{
    if (pos >= n)
        return s == 0;

    int &ans = dp[pos][s];

    if (vis[pos][s])
        return ans % mod;

    vis[pos][s] = 1;

    //ans = 0;

    int times = 0;
    while (times <= a[pos])
    {
        ans = (long long)(ans % mod) + (long long)ways(pos + 1, s - times) % mod;
        times += 1;
    }

    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n  ---> no. of children    k ---> no. of candies

    cin >> n >> k;
    a.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp.resize(n + 1, vector<int>(1e5 + 5, 0));
    vis.resize(n + 1, vector<int>(1e5 + 5, 0));

    cout << ways(0, k) << " " << endl;

    return 0;
}