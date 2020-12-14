#include <iostream>
#include <vector>
using namespace std;

/*******************   DP on Trees    *********************/

vector<int> adj[1000001];
int in[1000001];
int out[100001];
int dp[1000001];

int n;

void dfs_in(int node, int par) // Calculating the height (in height)
{
    in[node] = 0;

    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs_in(child, node);
            in[node] = max(in[node], in[child] + 1);
        }
    }
}

void dfs_out(int node, int par)
{
    int mx1 = -1, mx2 = -1;

    // finding the top 2 max values among siblings

    for (int child : adj[node])
    {
        if (child != par)
        {
            if (in[child] >= mx1)
            {
                mx2 = mx1;
                mx1 = in[child];
            }
            else if (in[child] > mx2)
            {
                mx2 = in[child];
            }
        }
    }

    for (int child : adj[node])
    {
        if (child != par)
        {
            int use = mx1;

            if (in[child] == mx1)
            {
                use = mx2;
            }

            out[child] = max(1 + out[node], 2 + use);
            dfs_out(child, node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y;

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs_in(1, 0);

    dfs_out(1, 0);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(in[i], out[i]);

        cout << dp[i] << " ";
    }

    return 0;
}