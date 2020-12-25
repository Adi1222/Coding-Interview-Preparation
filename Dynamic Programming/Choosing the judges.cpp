#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(int t)
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }

    if (n == 0)
    {
        cout << "Case " << t << ": "
             << "0" << endl;
        return;
    }
    else if (n == 1)
    {
        cout << "Case " << t << ": " << arr[0] << endl;
        return;
    }
    else if (n == 2)
    {
        cout << "Case " << t << ": " << max(arr[0], arr[1]) << endl;
        return;
    }
    else
    {
        int ans = 0;

        int incl = arr[0];
        int excl = 0;

        for (int k = 1; k < n; k++)
        {
            int previncl = incl;
            incl = max(arr[k] + excl, previncl);
            excl = previncl;
        }

        cout << "Case " << t << ": " << max(incl, excl) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    for (int m = 1; m <= t; m++)
    {

        solve(m);
    }

    return 0;
}