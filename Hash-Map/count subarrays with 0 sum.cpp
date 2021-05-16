#include <iostream>
#include <map>
using namespace std;

int main()
{
    int nums[] = {6, 3, -1, -3, 4, -2, 2,
                  4, 6, -12, -7};

    const int n = sizeof(nums) / sizeof(nums[0]);

    map<int, int> mp;

    mp[0] = 1;

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cur += nums[i];

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