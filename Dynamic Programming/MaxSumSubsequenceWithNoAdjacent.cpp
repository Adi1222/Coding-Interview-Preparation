#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/**** VARIOUS IMPLEMENTATIONS **********/

int main()
{

    vector<int> nums = {1, 2, 9, 4, 5, 0, 4, 11, 6};
    const int N = nums.size();

    // dp[i]  --> be the
    // i gues we have to consider 2 things till now 1) the score a2) the prev house that we robbed
    // since we are maximizing the score the value  of dp should be the max score i.e max houses that we've robbed so far

    vector<int> dp(N + 2, 0); // 2 based  dp

    for (int i = 0; i < N; i++)
    {
        dp[i + 2] = dp[i + 1];                       // if we do not consider the current house the score will be max score so far
        dp[i + 2] = max(dp[i + 2], nums[i] + dp[i]); // if we consider the current house
    }

    cout << dp[N + 1];

    //***************** Another Implementaion ************
    // dp[i]  --> be the
    // i gues we have to consider 2 things till now 1) the score a2) the prev house that we robbed
    // since we are maximizing the score the value  of dp should be the max score i.e max houses that we've robbed so far

    // curMax is max robbery till i house
    // pMax is max robbery till i - 1 house
    // ppMax is max robbery till i - 2 house
    int ppMax = 0, pMax = 0, curMax = 0;

    for (int i = 0; i < N; i++)
    {
        curMax = pMax;
        curMax = max(curMax, ppMax + nums[i]);
        ppMax = pMax;
        pMax = curMax;
    }

    cout << curMax;

    // ****************** Another implemenation ********************

    int incl = nums[0];
    int excl = 0;

    for (int i = 1; i < N; i++)
    {
        int temp = incl;
        incl = max(incl, excl + nums[i]);
        excl = temp;
    }

    cout << (incl >= excl) ? incl : excl;
}
