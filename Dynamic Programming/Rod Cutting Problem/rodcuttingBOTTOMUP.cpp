#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main(void)
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8}; // dummy
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = 4; // rod length

    // *************** BOTTOM UP APPROACH *********************/

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) // traversing through all length 1 .. to ... n
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + price[j - 1]);
        }
    }

    cout << "Max Profit is : " << dp[n] << " ";
    return 0;
}
