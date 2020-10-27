/*
    Aditya Chavan [{.}]  

*/

#include <iostream>
#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k; // k is the number of stones
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j] > i)
                break;

            if (dp[i - a[j]] == 0) // if I considering this and i am winning
            {
                dp[i] = 1;
                break;
            }

            // otherwise just continue your  search  for a  bigger number, choosing which you can win
        }
    }

    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}