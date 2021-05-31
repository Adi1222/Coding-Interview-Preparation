#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

// T.C O(Nlog(N))

int main()
{

    vector<vector<int>> vt = {{112567, 1, 2}, {112563, 3, 3}, {112569, 4, 7}, {112560, 9, 3}};

    int F = 112569;

    auto mycmp = [&](vector<int> v1, vector<int> v2)
    {
        if (v1[1] == v2[1])
            return v1[0] < v2[0];

        return v1[1] < v2[1];
    };

    sort(vt.begin(), vt.end(), mycmp);

    auto cmp = [&](pipii p1, pipii p2)
    {
        if (p1.first == p2.first)                     // if both trains become free at the same time
            return p1.second.first > p2.second.first; // increasing order of train number

        return p1.first > p2.first; // increasing order of release time
    };

    priority_queue<pipii, vector<pipii>, decltype(cmp)> pq(cmp);

    unordered_map<int, int> mp; // train num --> platform num.

    for (auto t : vt)
    {
        if (pq.empty())
        {
            pq.push({t[1] + t[2], {t[0], 1}});
        }
        else
        {
            if (!pq.empty() && pq.top().first < t[1])
            {
                auto itr = pq.top();

                pq.pop();

                itr.first = t[1] + t[2];

                pq.push(itr);

                mp[t[0]] = itr.second.second;
            }
            else
            {
                int platno = pq.size() + 1;

                pq.push({t[1] + t[2], {t[0], pq.size() + 1}});

                mp[t[0]] = platno;
            }
        }
    }

    cout << mp[F] << " " << endl;

    return 0;
}