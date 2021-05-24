#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{

    vector<int> vt = {1, 0, 0, 1, 0, 1, 1};

    map<int, int> mp;
    mp[0] = 1;

    int cur = 0;

    int ans = 0;

    for (int i = 0; i < vt.size(); i++)
    {
        (vt[i] == 0) ? (cur += -1) : (cur += 1);

        if (mp.find(cur) != mp.end())
        {
            ans += mp[cur];
            mp[cur]++;
        }
        else
        {
            mp[cur] = 1;
        }
    }

    cout << ans << " " << endl;

    return 0;
}