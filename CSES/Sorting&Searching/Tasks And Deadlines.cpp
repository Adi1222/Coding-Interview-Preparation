#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a, b;

    vector<pair<int, int>> vt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        vt[i] = {a, b};
    }

    sort(vt.begin(), vt.end());

    int ans = 0;
    int duration = 0;

    for (auto it : vt)
    {
        duration += it.first;
        ans += it.second - duration;
    }

    cout << ans << " ";
    return 0;
}