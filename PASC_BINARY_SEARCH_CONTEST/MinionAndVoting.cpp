/*

There are N minions who are competing in an election of the president of the ACM (Association of Cute Minions). They are standing in a line in the order from minion 1 to minion N. For each i (1 ≤ i ≤ N), the i-th minion has an influence level of Si.

A single minion may cast any number of votes. Minion j will vote for minion i (i ≠ j) if and only if the influence level of the j-th minion is greater than or equal to the sum of influence levels of all the minions standing between them (excluding the i-th and j-th minion).

Your task is to find the number of votes received by each minion.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of minions.
The second line contains N space-separated integers S1, S2, ..., SN.
Output

*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    ll n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[n + 1];
        ll sum[n + 1];
        ll count[n + 1];
        memset(sum, 0, sizeof(sum));
        memset(count, 0, sizeof(count));
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int i = 1; i <= n; i++)
        {

            for (int j = i + 1; j <= n; j++)
            {
                if (abs(sum[j - 1] - sum[i]) <= arr[i])
                    count[j]++;
                else
                    break;
            }
        }
        for (int i = 1; i <= n; i++)
        {

            for (int j = i - 1; j >= 1; j--)
            {
                if (abs(sum[i - 1] - sum[j]) <= arr[i])
                    count[j]++;
                else
                    break;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << count[i] << " ";
        cout << endl;
    }
    return 0;
}
