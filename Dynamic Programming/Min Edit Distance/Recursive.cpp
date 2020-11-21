#include <iostream>
#include <string>
#define int long long int
#define mod 1000000007
using namespace std;

/********      Recursive solution         ***********/

int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int solve(string s1, string s2, int m, int n)
{
    // base case

    if (m == 0)
    {
        return n;
    }

    if (n == 0)
    {
        return m;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return solve(s1, s2, m - 1, n - 1);
    }

    return 1 + min(solve(s1, s2, m, n - 1), solve(s1, s2, m - 1, n), solve(s1, s2, m - 1, n - 1));
}

signed main()
{
    string s1 = "saturday";
    string s2 = "sunday";

    cout << solve(s1, s2, s1.length(), s2.length()) << " " << endl;

    return 0;
}