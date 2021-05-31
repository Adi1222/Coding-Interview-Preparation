#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    vector<int> apples = {3, 0, 0, 0, 0, 2};
    vector<int> days = {3, 0, 0, 0, 0, 2};

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    const int N = apples.size();

    int day = 1;

    int cnt = 0;

    for (int i = 0; i < apples.size(); i++)
    {
        pq.push({day + days[i], apples[i]});

        // there might be some apples which are already rotten --just remove them

        while (!pq.empty() && day >= pq.top().first)
        {
            pq.pop();
        }

        if (!pq.empty())
        {
            auto it = pq.top();

            pq.pop();

            it.second--;

            if (it.second > 0)
            {
                pq.push(it);
            }

            cnt += 1;
        }

        day += 1;
    }

    while (!pq.empty())
    {
        while (!pq.empty() && day >= pq.top().first)
        {
            pq.pop();
        }

        if (!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            itr.second--;

            if (itr.second > 0)
            {
                pq.push(itr);
            }

            cnt += 1;
        }

        day += 1;
    }

    cout << cnt << " " << endl;

    return 0;
}