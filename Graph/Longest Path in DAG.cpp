#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// T . C: O(N)

vector<int> adj[100005];
vector<int> vis(1001, 0);

vector<int> dp(1000005, 0);

int n, m;

void dfs(int node)
{
    vis[node] = 1;

    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }

        dp[node] = max(dp[node], 1 + dp[child]); // count of parent depends on child we will add it to parent after the child  is computed
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;

        cin >> x >> y;

        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << " ";

    return 0;
}