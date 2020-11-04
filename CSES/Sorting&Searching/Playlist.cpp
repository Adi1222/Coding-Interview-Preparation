#include <bits/stdc++.h>
using namespace std;

#define io                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long int

int32_t main()
{
    io int n;
    cin >> n;
    map<int, int> mp;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int left = 1, ans = 0;
    for (int right = 1; right <= n; right++)
    {
        left = max(left, mp[a[right]] + 1);
        ans = max(ans, right - left + 1);
        mp[a[right]] = right;
    }

    cout << ans << endl;
}