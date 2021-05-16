#include <iostream>
#include <map>
using namespace std;

int main()
{
    int nums[] = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    const int n = sizeof(nums) / sizeof(nums[0]);

    map<int, int> mp;

    int dis = 0;

    for (int i = 0; i < k; i++)
    {
        if (mp[nums[i]] == 0)
        {
            dis += 1;
        }

        mp[nums[i]]++;
    }

    cout << dis << " ";

    for (int i = k; i < n; i++)
    {
        if (mp[nums[i - k]] == 1)
        {
            dis -= 1;
        }

        mp[nums[i - k]]--;

        mp[nums[i]]++;

        if (mp[nums[i]] == 1)
        {
            dis += 1;
        }

        cout << dis << " ";
    }
    return 0;
}