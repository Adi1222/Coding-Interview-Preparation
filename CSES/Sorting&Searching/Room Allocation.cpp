#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int tot = 0;

    vector<pair<pair<int, int>, int>> vt(200005);
    vt.resize(n);
    int ans[200005];

    for (int i = 0; i < n; i++)
    {
        cin >> vt[i].first.first >> vt[i].first.second;
        vt[i].second = i; // for storing the index
    }

    sort(vt.begin(), vt.end()); // sorting based on starting time

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // storing departure time in creasing order

    int last = 0;

    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            last += 1;
            pq.push({vt[i].first.second, last});
            ans[vt[i].second] = last;
        }
        else
        {
            auto it = pq.top();

            if (it.first < vt[i].first.first)
            {
                pq.pop();
                pq.push({vt[i].first.second, it.second});
                ans[vt[i].second] = it.second;
            }

            else
            {
                //int room = pq.top().second;
                //room += 1;
                last++;
                pq.push({vt[i].first.second, last});
                ans[vt[i].second] = last;
            }
        }

        tot = max(tot, (int)pq.size());
    }

    cout << tot << " " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}