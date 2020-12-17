#include <iostream>
#include <vector>
using namespace std;

/**********       T.C O(N log(N)) ******************/

int main()
{
    vector<int> arr = {1, 2, 10, 4};

    int n = arr.size();
    int k = 14;

    int prefix[5];
    memset(prefix, 0, sizeof(prefix));

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int ans = -1;

    int left = 1, right = n;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int i;

        // checking for all subarrays of size mid

        for (i = mid; i <= n; i++)
        {
            if (prefix[i] - prefix[i - mid] > k)
            {
                break; // this value of mid cannot be the ans
            }
        }

        if (i == n + 1)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans << " ";

    return 0;
}