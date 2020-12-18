#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

/**************    T.C O(N) + sorting takes O(NlogN)               ************/

// Binary Search  + Combinatorics Approach

// Link to problem description https://codeforces.com/contest/1462/problem/E1

ll combinatorics(ll n)
{
    return n * (n + 1) / 2;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll f = a[i];
        ll l = 2 + a[i];

        int mid = upper_bound(a.begin(), a.end(), l) - a.begin();
        --mid;

        if (mid - i >= 2)
        {
            ans += combinatorics(mid - i - 1);
        }
    }

    cout << ans << " " << endl;
}

int main()
{
    // your code goes here

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}