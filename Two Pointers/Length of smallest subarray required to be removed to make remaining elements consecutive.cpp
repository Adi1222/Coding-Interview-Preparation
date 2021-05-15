#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vt = {7, 8, 1, 2, 5, 6, 7, 8, 9, 10};

    int L, R;

    const int n = vt.size();
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (vt[i] + 1 != vt[i + 1])
            break;
    }

    L = i;

    for (i = n - 1; i > 0; i--)
    {
        if (vt[i - 1] + 1 != vt[i])
        {
            break;
        }
    }

    R = i;

    int ans = min(R, n - L - 1);

    int cnt = 0;
    int r = R;
    if (vt[r] <= vt[L] + 1)
    {
        while (r < n && vt[r] < vt[L])
        {
            cnt += 1;
            r++;
        }

        int temp = R - L - 1;
        int x = min(cnt, L + 1);

        ans = min(ans, temp + x);
    }

    cout << ans << " " << endl;

    return 0;
}