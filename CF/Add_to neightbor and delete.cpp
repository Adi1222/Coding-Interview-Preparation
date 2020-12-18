#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int isPossible(vector<int> &a, int ht)
{
    int tot = 0;
    int left = 0;
    int s = 0;
    int n = a.size();

    for (int right = 0; right < n; right++)
    {
        s += a[right];

        if (s == ht)
        {
            tot += (right - left);
            s = 0;
            left = right + 1;
        }
        else
        {
            if (s > ht)
            {
                return -1;
            }
        }
    }

    return tot;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int ans = n - 1;

    // finding factors

    for (int i = 1; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            int f1 = i;
            int f2 = sum / i;

            int a1 = isPossible(a, f1);
            int a2 = isPossible(a, f2);

            if (a1 != -1)
            {
                ans = min(ans, a1);
            }

            if (a2 != -1)
            {
                ans = min(ans, a2);
            }
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