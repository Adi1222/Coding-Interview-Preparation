#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 1, 0, 0, 1, 1};
    int k = 1;

    const int n = sizeof(arr) / sizeof(arr[0]);

    int l = 0, r;

    int cnt = 0;
    int ans = 0;

    for (r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            cnt += 1;
        }

        if (cnt <= k)
        {
            ans = max(ans, r - l + 1);
        }
        else
        {
            while (l < r && cnt > k)
            {
                if (arr[l] == 0)
                {
                    cnt -= 1;
                }

                l++;

                if (cnt == k)
                {
                    ans = max(ans, r - l + 1);
                }
            }
        }
    }

    cout << ans << " " << endl;
    return 0;
}