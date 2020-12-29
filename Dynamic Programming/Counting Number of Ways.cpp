#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

/*
long long ways(int x, int k, int cur)
{
	if(cur > x)
	{
		return -1;
	}
	
	if(cur == x)
	{
		return 1;
	}
	
	long long ans = dp[cur];
	ans %= MOD;
	
	if(vis[cur])
	{
		return ans;
	}
	
	vis[cur] = 1;
	
	ans = 0;
	
	
	for(int i = 1; i <= k; i++)
	{
		if(i + cur <= x)
		{
			long long temp = ways(x, k, cur + i);
			
			if(temp > 0)
			{
				ans = ans + temp;
				ans %= MOD;
			}
		}
	}
	
	return dp[cur] = ans;
	
	
	
}*/

void solve()
{
    int x, k;

    cin >> x >> k;

    vector<int> dp(x + 1, 0);

    //cout<<ways(x, k, 0)<<endl;

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j <= i)
            {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    /*for(int i = 0; i <= x; i++)
	{
		cout<<dp[i]<<" ";
	}*/
    //cout<<"*"<<endl;

    cout << dp[x] << " " << endl;
}

int main()
{
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