#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100001];
int vis[100001], dist[10001];
int n, m, a, b;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;

    while (!q.empty())
    {
        int c = q.front();
        q.pop();

        for (int child : adj[c])
        {
            if (!vis[child])
            {
                q.push(child);
                dist[child] = dist[c] + 1;
                vis[child] = 1;
            }
        }
    }
}

void solve()
{

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < n; i++)

        bfs(1);

    cout << dist[n] << " " << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        solve();
    }

    return 0;
}