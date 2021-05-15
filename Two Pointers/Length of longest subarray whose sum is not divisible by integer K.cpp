#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Longest subarray with sum not divisible by X

int main()
{

    vector<int> vt = {1, 2, 2, 3, 1, 2, 3};
    int n = vt.size();

    int ans = -1;
    int index = INT_MAX;
    int prefix = 0;

    for (int i = 0; i < n; i++)
    {
        prefix += vt[i];

        if (prefix % 3 != 0)
        {
            index = min(index, i);
            ans = max(ans, i + 1);
        }
        else
        {
            if (index != INT_MAX)
            {
                ans = max(ans, i - index);
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}