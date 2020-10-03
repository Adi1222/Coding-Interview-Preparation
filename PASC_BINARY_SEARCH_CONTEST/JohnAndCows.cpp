/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
*/



#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int arr[100005];

bool canPlaceCows(int mid, int n, int k)
{
    // 1
    int cows = 1;       // placed one cow
    int place = arr[0]; // placed at the first stalk value

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - place >= mid)
        {
            cows += 1;      // updated the number of cows placed
            place = arr[i]; // update the stalk position of the newly placed cow
        }
    }

    if (cows >= k)
    {
        return true;
    }

    return false;
}

int BS(int n, int k)
{
    int l = 1;
    int h = arr[n - 1] - arr[0];

    while (h - l > 1)
    {
        int mid = l + (h - l) / 2;

        if (canPlaceCows(mid, n, k))
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }

    if (canPlaceCows(h, n, k))
    {
        return h;
    }

    if (canPlaceCows(l, n, k))
    {
        return l;
    }

    return 0;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k; // n --> no. of stalls k ---> no. of cows
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        cout << BS(n, k) << endl;
    }

    return 0;
}
