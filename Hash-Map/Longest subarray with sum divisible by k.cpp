#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vt = {2, 7, 6, 1, 4, 5};
    int k = 3;
    int n = vt.size();

    unordered_map<int, int> mp;

    int ans = 0;
    int cur = 0;

    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        cur += vt[i];
        int r = ((cur % k) + k) % k;

        // or int r = cur % k;
        // if (r < 0) { r += k; };

        if (mp.find(r) != mp.end())
        {
            ans = max(ans, i - mp[r]);
        }
        else
        {
            mp[r] = i;
        }
    }

    cout << ans << " " << endl;

    return 0;
}