#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, n;

    cin >> x >> n;

    set<int> st = {0, x};

    multiset<int> len = {x};

    int point;

    for (int i = 0; i < n; i++)
    {
        cin >> point;

        auto it = st.upper_bound(point);

        int left = *prev(it);
        int right = *it;

        len.erase(len.find(right - left));

        len.insert(point - left);
        len.insert(right - point);

        st.insert(it, point);

        cout << *len.rbegin() << " ";
    }

    return 0;
}