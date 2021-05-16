#include <iostream>
#include <map>
using namespace std;

// O(N)

int main()
{
    int nums[] = {15, -2, 2, -8, 1, 7, 10, 23};

    const int n = sizeof(nums) / sizeof(nums[0]);

    map<int, int> mp;

    mp[0] = -1;

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cur += nums[i];

        if (mp.find(cur) != mp.end())
        {
            ans = max(ans, i - mp[cur]);
        }
        else
        {
            mp[cur] = i;
        }
    }

    cout << ans << " " << endl;

    return 0;
}