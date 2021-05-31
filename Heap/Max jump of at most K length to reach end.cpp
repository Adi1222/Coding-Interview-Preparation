#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

// T.C ---> O(N*log(K))  b'coz at any moment the priority queue will have at most k elements

int main()
{
    vector<int> vt = {-44, -17, -54, 79};

    int k = 2;

    const int N = vt.size();

    priority_queue<pi> pq;

    int ans = vt[0];

    for (int i = 0; i < N; i++)
    {
        pq.push({ans, i});

        // removing the elements that do not lie in the range

        while (!pq.empty() && pq.top().second < (i - k))
        {
            pq.pop();
        }

        ans = vt[i] + pq.top().first;
    }

    cout << ans << " " << endl;

    return 0;
}