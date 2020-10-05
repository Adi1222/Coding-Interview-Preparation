#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> vt = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};



    const int N = vt.size();

    sort(vt.begin(), vt.end(), [&](vector<int> &a, vector<int> &b) { return a[2] > b[2]; }); // Sort all jobs according to decreasing order of profit

    vector<int> ans, slot;
    ans.resize(N, 0);
    slot.resize(N, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = min(N, vt[i][1]) - 1; j >= 0; j--)
        {
            if (!slot[j]) // if available
            {
                slot[j] = 1;
                ans[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (slot[i])
        {
            cout << vt[ans[i]][0] << " ";
        }
    }

    return 0;
}