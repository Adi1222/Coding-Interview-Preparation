#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        auto itr = upper_bound(v.begin(), v.end(), vt[i]);

        if (itr != v.end())
        {
            *itr = vt[i];
        }
        else
        {

            v.push_back(vt[i]);
        }
    }

    cout << v.size() << " " << endl;

    return 0;
}