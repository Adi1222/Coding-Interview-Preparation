#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// T.C O(nlog(n))

int main()
{
    // your code goes here

    vector<int> A = {90, 49, 20, 39, 49};
    vector<int> B = {14, 24, 82};

    int X = 15;

    int N = A.size();
    int M = B.size();

    sort(A.begin(), A.end());

    sort(B.begin(), B.end());

    multiset<int> ms;
    for (int x : B)
        ms.insert(x);

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int lo = A[i] - X;

        auto itr = ms.lower_bound(lo);

        if (itr != ms.end())
            ;
        {
            if (*itr <= (A[i] + X))
            {
                ans += 1;
                ms.erase(itr);
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}