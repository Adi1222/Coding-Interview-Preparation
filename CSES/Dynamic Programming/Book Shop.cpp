#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {

            dp[i][j] = dp[i - 1][j];

    
            if (price[i - 1] <= j)
            {
                // now we have have 2 options
                // either consider that book
                // or don't consider that book
                // at the end we gonna select the option which will have max pages

                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]); // i - 1 b'coz we can consider the book atmost once
            }
        }
    }

    cout << dp[n][x] << " " << endl;

    return 0;
}