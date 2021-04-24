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

    multiset<int> ms;

    for (int i = 0; i < N; i++)
    {
        int flag = 0;
        if (!ms.empty())
        {
            auto it = ms.lower_bound(vp[i].first);

            if (it != ms.end())
            {
                if (*it <= vp[i].first)
                {
                    ms.erase(it); // deleting the previously visited shop b'coz at one time any person can visit only one shop

                    ms.insert(vp[i].second);

                    cnt += 1;
                    flag = 1;
                }
            }
        }

        if (!flag && ms.size() < k)
        {
            cnt += 1;
            ms.insert(vp[i].second);
        }
    }

    cout << count << " ";

    return 0;
}