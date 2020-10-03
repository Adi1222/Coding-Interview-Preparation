/*

Appy loves balloons! She wants you to give her balloons on each of N consecutive days (numbered 1 through N); let's denote the number of balloons Appy wants on day i by Ai. The problem is that you only have M balloons. Fortunately, you can give her candies instead of balloons as well. On each day i, Appy accepts Bi candies per each balloon you do not give her — formally, if you give Appy Xi balloons on day i, then you have to give her Ci=max(0,Ai−Xi)⋅Bi candies as well.

Your task is to minimize the maximum number of candies you give Appy on some day — find the minimum possible value of max(C1,C2,C3,…,CN).

Input
The first line of the input contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output
Print a single line containing one integer — the minimum value of max(C1,C2,C3,…,CN).

*/



#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[N], b[N];
ll n, m;

bool isPossible(ll mid)
{
    ll req = 0;

    for (int i = 0; i < n; i++)
    {

        ll temp = a[i] - (mid / b[i]);

        if (temp > 0)
        {
            req += temp;
        }
    }

    if (req > m)
    {
        return false;
    }

    return true;
}

int BS(ll h)
{
    ll low = 0;
    ll high = h;

    while (low < high)
    {
        ll mid = low + (high - low) / 2;

        if (isPossible(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;

    return 0;
}

int main()
{
    // your code goes here

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll h = 0;

    for (int i = 0; i < n; i++)
    {
        h = max(h, a[i] * b[i]);
    }

    BS(h);

    return 0;
}
