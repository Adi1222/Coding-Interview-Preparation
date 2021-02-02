/*
    Aditya Chavan
*/

#include <iostream>
#include <bits/stdc++.h>
//#define int  long long
#define lli long long int
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int N = 1e6 + 5;
vector<bool> prime(N, true);

long long mod(long long x)
{
    return (((x % MOD) + MOD) % MOD);
}

long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}

ll modPow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % MOD;

    ll res = 1;

    while (b)
    {
        if (b % 2 == 1) // odd
            res = mul(res, a);

        a = mul(a, a);
        b = b / 2;
    }

    return res;
}

void seive()
{

    prime[1] = prime[0] = false;

    for (ll i = 2; i < N; i++)
    {
        if (prime[i] == true)
        {
            //cout<<i<<" ";
            for (ll j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve()
{

    int n;
    cin >> n;

    int minx = 1e6 + 5, maxx = -1;

    int a;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (prime[a]) // if prime
        {

            minx = min(minx, a);
            maxx = max(maxx, a);
        }
    }

    if (minx == 1e6 + 5 || maxx == -1)
    {
        cout << "-1";
    }
    else
    {
        cout << abs(maxx - minx) << " ";
    }
}

signed main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;

    //while(t--)
    //	{

    seive();
    solve();
    //	}

    return 0;
}