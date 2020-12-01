#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int fun(vector<int> &a, int x, int pos, int cond)
{
    // base case
    if (pos == a.size())
        return 0;

    int &temp = dp[pos][cond];

    if (dp[pos][cond] != -1)
        return temp;

    temp = 0;

    if (cond == 0) // we haven't considered multiplying to any element yet
    {
        // here again we use kadane's algorithm knowledge
        temp = max(temp, a[pos] + fun(a, x, pos + 1, 0));

        temp = max(temp, x * a[pos] + fun(a, x, pos + 1, 1));
    }
    else if (cond == 1) // we have considered multiplying element with x
    {
        // here again we use kadane's algorithm knowledge
        temp = max(temp, x * a[pos] + fun(a, x, pos + 1, 1));

        temp = max(temp, a[pos] + fun(a, x, pos + 1, 2));
    }
    else // we have already considered our subarray
    {
        temp = max(temp, a[pos] + fun(a, x, pos + 1, 2));
    }

    return temp;
}

void solve(vector<int> &a, int n, int x)
{

    dp.resize(n, vector<int>(3, -1));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, fun(a, x, i, 0));
    }

    cout << ans << " ";

    return;
}

int main()
{

    vector<int> a = {1, 2, 4, -10};
    int n = a.size();
    int x = 2;

    solve(a, n, x);

    return 0;
}