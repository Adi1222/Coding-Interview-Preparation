#include <iostream>
#include <vector>
#define int long long int
#define mod 1000000007
using namespace std;

/********      DP solution       ***********/

int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

signed main()
{
    string s1 = "saturday";
    string s2 = "sunday";

    const int m = s1.length();
    const int n = s2.length();

    vector<vector<int>> dp;

    dp.resize(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    cout << dp[m][n] << " " << endl;

    return 0;
}