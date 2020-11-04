#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod ((int)(1e9 + 7))

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    multiset<int, greater<int>> ms; // for set contaning duplicates and sorted in decreasing order

    int ticket, cust;

    for (int i = 0; i < n; i++)
    {
        cin >> ticket;

        ms.insert(ticket);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> cust;

        auto itr = ms.lower_bound(cust);

        if (itr == ms.end())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << *itr << " " << endl;
            ms.erase(itr);
        }
    }

    return 0;
}