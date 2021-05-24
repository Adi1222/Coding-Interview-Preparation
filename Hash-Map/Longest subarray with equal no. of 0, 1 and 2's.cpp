#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{

    vector<int> vt = {0, 1, 0, 2, 0, 1, 0};

    int ans = -1;

    map<string, int> mp;

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    int diff10 = 0;
    int diff21 = 0;

    char ch1 = '0' + diff10;
    char ch2 = '0' + diff21;

    string key = "";
    key = ch1 + '#' + ch2;

    mp[key] = -1;

    for (int i = 0; i < vt.size(); i++)
    {
        if (vt[i] == 0)
        {
            cnt0 += 1;
        }
        else if (vt[i] == 1)
        {
            cnt1 += 1;
        }
        else
        {
            cnt2 += 1;
        }

        diff10 = cnt1 - cnt0;
        diff21 = cnt2 - cnt1;

        string temp = "";

        ch1 = '0' + diff10;
        ch2 = '0' + diff21;

        temp = ch1 + '#' + ch2;

        if (mp.find(temp) != mp.end())
        {
            ans = max(ans, i - mp[temp]);
        }
        else
        {
            mp[temp] = i;
        }
    }

    cout << ans << " " << endl;

    return 0;
}