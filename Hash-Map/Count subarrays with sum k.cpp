#include <iostream>
#include <map>
using namespace std;

// T.C O(N)

int main()
{
    int nums[] = {10, 2, -2, -20, 10};

    int k = -10;

    const int n = sizeof(nums) / sizeof(nums[0]);

    map<int, int> mp;

    mp[0] = 1;

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cur += nums[i];

        if (mp.find(cur - k) != mp.end())
        {
            ans += mp[cur - k];
        }

        mp[cur]++;
    }

    cout << ans << " " << endl;

    return 0;
}