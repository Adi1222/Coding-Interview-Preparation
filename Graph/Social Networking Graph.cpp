#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[1000005];
int vis[1000001];
int dist[1000001];
int cnt[1000001]; // number of nodes at a distance of i from source

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0; // distance of source from source is 0

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (int child : adj[t])
        {
            if (!vis[child])
            {
                dist[child] = dist[t] + 1;
                q.push(child);
                vis[child] = 1;
                cnt[dist[child]] += 1; // increment the no of nodes having that distance
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, e, a, b, q, src, d;

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> q;

    while (q--)
    {
        cin >> src >> d;

        for (int i = 0; i <= n; i++)
        {
            vis[i] = 0;
            cnt[i] = 0;
            dist[i] = 0;
        }

        bfs(src);

        cout << cnt[d] << " " << endl; // i.e how many elements are there at d distance
    }

    return 0;
}