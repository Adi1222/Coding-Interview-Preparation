/*

    Aditya Chavan

*/

#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define lli long long int
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int N = 1e7 + 5;
const int M = 1e5 + 5;
vector<bool> prime(N, true);
vector<int> prefix(M);

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
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    prefix.clear();
    prefix.resize(n + 5);
    prefix[1] = arr[1];

    for (int i = 2; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << " " << endl;
    }
}

signed main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
