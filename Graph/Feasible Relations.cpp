#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[1000005];
vector<int> vis(1000001);
int cur;
vector<int> cc(1000001);

void dfs(int node)
{
    vis[node] = 1;
    cc[node] = cur;

    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

void solve()
{
    int n, k, a, b;
    string op = "";

    vector<pair<int, int>> vp;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis.resize(n, 0);
        cc.resize(n, 0);
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> a >> op >> b;

        if (op == "=")
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        else
        {
            vp.push_back({a, b});
        }
    }

    for (int i = 1; i <= n; i++) // first let us find the component each node belongs to
    {
        if (!vis[i])
        {
            cur += 1;
            dfs(i);
        }
    }

    bool flag = true;

    for (int i = 0; i < vp.size(); i++)
    {

        if (cc[vp[i].first] == cc[vp[i].second])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "YES"
             << " " << endl;
    }
    else
    {
        cout << "NO"
             << " " << endl;
    }
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
        cur = 0;

        solve();
    }

    return 0;
}