#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    // take input start and end;

    vector<pair<int, int>> res;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < start.size(); i++)
    {
        pq.push({end[i], start[i]}); // key is destination
    }

    auto it = pq.top();
    int st = it.second;
    int ed = it.first;
    pq.pop();
    res.push_back({st, ed});

    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();
        if (itr.second >= ed)
        {
            st = itr.second;
            ed = itr.first;
            res.push_back({st, ed});
        }
    }

    cout << "Selected Activities;" << endl;

    for (auto it : res)
    {
        cout << it.first << " " << it.second << " " << endl;
    }

    return 0;
}