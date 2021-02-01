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

const int N = 1e7 + 5;
vector<bool> prime(N, true);
vector<int> uprime(N);

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

    for (int i = 2; i < N; i++)
    {
        if (prime[i] == true)
        {
            int cur = 0;
            int temp = i;
            while (i)
            {
                cur += i % 10;
                i /= 10;
            }

            i = temp;
            if (prime[cur] == true)
            {

                uprime[i] = 1;
            }
            else
            {
                uprime[i] = 0;
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        uprime[i] += uprime[i - 1];
    }
}

void solve()
{
    int l, r;

    cin >> l >> r;

    cout << uprime[r] - uprime[l - 1] << " " << endl;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uprime[0] = 0;
    prime[1] = true;
    prime[0] = true;
    uprime[1] = 0;

    seive();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
