#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define hell 1000000007
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
#define take(a, b, c)       \
    for (b = 0; b < c; b++) \
        scanf("%d", &a[b]);

void dfs(vector<vector<int>> &graph, vector<int> &vis, int st, int m, int count, vector<int> &cats)
{
    vis[st] = 1;

    for (int i = 0; i < graph[st].size(); i++)
    {
        int cur = graph[st][i];
        int temp = 0;

        if (cats[st] == 1 && cats[cur] == 1)
        {
            temp = count + 1;
        }
        else if (cats[cur])
        {
            temp = 1;
        }
        else
        {
            temp = 0;
        }

        if (temp > m)
        {
            continue;
        }

        dfs(graph, vis, cur, m, temp, cats);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m; // n --> no of verices   m --> max no of cats allowed

    vector<int> cats(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cats[i];
    }
    vector<int> vis(n, 0);

    vector<vector<int>> graph;
    graph.resize(n, vector<int>(200001));

    for (int i = 0; i < n - 1; i++)
    {
        int l, r;
        cin >> l >> r;
        graph[l - 1].pb(r - 1);
        graph[r - 1].pb(l - 1);
    }

    int count = 0;
    if (cats[0] == 1)
    {
        count = 1;
    }

    dfs(graph, vis, 0, m, count, cats);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] && graph[i].size() == 1 && i != 0)
        {
            ans += 1;
        }
    }

    cout << ans << " " << endl;

    return 0;
}