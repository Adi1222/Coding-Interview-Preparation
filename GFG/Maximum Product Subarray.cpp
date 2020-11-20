#include <iostream>
#include <vector>
#define int long long int
using namespace std;

// T. C   0(n)
signed main()
{
    vector<int> v = {1, -2, -3, 0, 7, -8, -2};

    const int N = v.size();

    int max_prod_cur = v[0];
    int min_prod_cur = v[0];

    int max_prod_prev = v[0];
    int min_prod_prev = v[0];

    int ans = v[0];

    for (int i = 1; i < N; i++)
    {
        max_prod_cur = max({v[i], max_prod_prev * v[i], min_prod_prev * v[i]});
        min_prod_cur = min({v[i], max_prod_prev * v[i], min_prod_prev * v[i]});

        ans = max(ans, max_prod_cur);

        max_prod_prev = max_prod_cur;
        min_prod_prev = min_prod_cur;
    }

    cout << ans << " ";

    return 0;
}