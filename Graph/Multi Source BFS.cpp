#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// T.C O(v + e)

vector<int> adj[10001];
vector<int> vis(1001);

int dist[7];

void bfs(int src)
{
    queue<int> q;

    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        vis[c] = 1;

        for (int child : adj[c])
        {
            if (!vis[child])
            {
                q.push(child);

                if (dist[child])
                {
                    dist[child] = min(dist[child], dist[c] + 1);
                }
                else
                {
                    dist[child] = dist[c] + 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    int x, y;

    cin >> n >> m;

    vector<int> police = {1, 5};
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }

    vis.resize(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    /*for(int i = 0; i < police.size(); i++)
	{
		vis.resize(n+1,0);
		bfs(police[i]);
	}*/

    bfs(police[0]);
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
    }
    bfs(police[1]);

    for (int i = 0; i < police.size(); i++)
    {
        dist[police[i]] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> " << dist[i] << " " << endl;
    }

    return 0;
}