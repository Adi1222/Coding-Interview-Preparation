#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
     int n = nums.size();
     int k;
    map<int, int> mp;

    int ans = 0;
    int cur = 0;

    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        cur += nums[i];

        if (mp.find(cur - k) != mp.end())
        {
            ans += mp[cur - k];
        }

        if (mp.find(cur) == mp.end())
        {
            mp[cur] = 1;
        }
        else
            mp[cur]++;
    }

    cout << ans << " " << endl;
}