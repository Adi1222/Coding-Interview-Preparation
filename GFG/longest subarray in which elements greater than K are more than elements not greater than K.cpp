#include <iostream>
#include <vector>
using namespace std;

// T.C 0(N*log(N))

int solve(vector<int> &a, int n, int k)
{
    vector<int> pre(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
            pre[i] = 1;
        else
            pre[i] = -1;
    }

    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + pre[i];

    int ans = 0;

    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        bool isPossible = false;

        for (int i = mid - 1; i < n; i++)
        {

            int x = pre[i];

            if (i - mid >= 0)
                x -= pre[i - mid];

            if (x > 0)
            {
                isPossible = true;
                break;
            }
        }

        if (isPossible == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n, k) << " ";

    return 0;
}