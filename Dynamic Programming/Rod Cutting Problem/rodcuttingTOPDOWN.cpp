#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// *************** TOP DOWN APPROACH *********************/

int rodcut(vector<int> &price, int l, vector<int> &dp, vector<int> &visited)
{
    // base case
    if (l == 0)
    {
        return 0;
    }

    int &ans = dp[l];
    if (visited[l])
    {
        return ans;
    }

    // otherwise set visited as TRUE
    visited[l] = 1;

    ans = INT_MIN;

    for (int i = 1; i <= l; i++)
    {
        int tempcost = price[i - 1] + rodcut(price, l - i, dp, visited);

        ans = max(ans, tempcost);
    }

    return ans;
}

int main(void)
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8}; // dummy
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = 4; // rod length

    vector<int> dp, visited;
    dp.resize(n + 1, 0);
    visited.resize(n + 1, 0);

    cout << "Max Profit is : " << rodcut(price, n, dp, visited) << " ";
    return 0;
}
