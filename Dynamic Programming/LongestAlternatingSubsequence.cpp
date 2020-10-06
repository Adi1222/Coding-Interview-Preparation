

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b)
{
    return (a >= b) ? (a) : (b);
}

int main()
{
    vector<int> A = {8, 9, 6, 4, 5, 7, 3, 2, 4};
    const int N = A.size();

    vector<vector<int>> dp;
    dp.resize(N, vector<int>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    if (N < 2)
    {
        cout << "1";
        return 0;
    }

    int ans = INT_MIN;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                ans = max(ans, dp[i][1]);
            }
            else if (A[i] < A[j])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                ans = max(ans, dp[i][0]);
            }
            else
            {
                continue;
            }
        }
    }

    cout << "Longest length is: " << ans << " ";

    return 0;
}