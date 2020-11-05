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

    set<int> st;

    for (int i = 1; i <= x; i++)
    {
        st.insert(i);
    }

    int l;
    int prev = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> l;

        if (st.count(l) == 1)
        {
            int s = *st.begin();
            int end = *st.end();

            int d1 = l - s;
            int d2 = end - l;
            auto it = st.find(l);

            if (d2 >= d1)
            {

                st.erase(st.begin(), ++it);

                prev = st.size();

                cout << prev << " ";
            }
            else
            {
                ++it;
                st.erase(it, st.end());
                prev = st.size();
                cout << prev << " ";
            }
        }
        else
        {
            cout << prev << " ";
        }
    }

    return 0;
}