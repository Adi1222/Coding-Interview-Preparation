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

    int n;

    cin >> n;

    vector<vector<int>> vt;
    vt.resize(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> vt[i][0];
        cin >> vt[i][1];
    }

    sort(vt.begin(), vt.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(vt[0][1]);

    int people = 1;

    for (int i = 1; i < n; i++)
    {
        while (!pq.empty() && vt[i][0] > pq.top())
        {
            pq.pop();
        }

        pq.push(vt[i][1]);

        int temp = pq.size();

        people = max(temp, people);
    }

    cout << people << " " << endl;

    return 0;
}