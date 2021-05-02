#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// T.C O(nlog(n))

bool mycomp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    // your code goes here

    vector<pair<int, int>> vp;

    sort(vp.begin(), vp.end(), mycomp);

    int cnt = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {

        while (!pq.empty() && pq.top() <= vp[i].first)
        {
            pq.pop();
        }

        if (pq.size() < k)
        {
            pq.push(vp[i].second);
            cnt += 1;
        }
    }

    cout << cnt << " ";

    return 0;
}