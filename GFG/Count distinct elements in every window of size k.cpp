#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// T.C: O(n)

int main()
{
    vector<int> vt = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    const int n = vt.size();

    unordered_map<int, int> mp;

    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        if (mp[vt[i]] == 0)
        {
            cnt += 1;
        }

        mp[vt[i]] += 1;
    }

    cout << cnt << " ";

    for (int i = k; i < n; i++)
    {
        if (mp[vt[i - k]] == 1)
        {
            cnt -= 1;
        }

        mp[vt[i - k]] -= 1;

        if (mp[vt[i]] == 0)
        {
            cnt += 1;
        }

        mp[vt[i]] += 1;

        cout << cnt << " ";
    }

    cout << endl;

    return 0;
}