#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[10001];
int arr[10001];
int dp[10001];

void dfs(int node, int par)
{
    dp[node] = arr[node];
    int mx = 0;

    for (int child : adj[node])
    {
        if (child ! = par)
        {
            dfs(child, node);
            mx = max(mx, dp[chid]);
        }
    }

    dp[node] += mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;

    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // take node values input
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dfs(1, 0);

    cout << dp[1] << " ";

    return 0;
}