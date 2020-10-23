#include <iostream>
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

int cnt = 0;

void dfs(vector<int> *graph, vector<int> &vis, int st, int **mat)
{
    vis[st] = 1;
    mat[0][st] = cnt; // arrival time

    for (int i = 0; i < graph[st].size(); i++)
    {
        int child = graph[st][i];

        if (!vis[child])
        {
            cnt++;
            dfs(graph, vis, child, mat);
        }
    }

    cnt += 1;
    mat[1][st] = cnt; // while departure

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q; // n -> nodes and q --> queries
    cin >> n >> q;

    vector<vector<int>> graph; // becuse node index start from 1
    graph.resize(n + 1, vector<int>(20000));
    //vector<int> *graph = new vector<int>[n + 1];

    for (int i = 0; i < n - 1; i++) // because n - 1 edges
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    vector<vector<int>> mat;

    mat.resize(n + 1, vector<int>(2, 0));

    /*int **mat = new int[2];
    for (int i = 0; i < 2; i++)
    {
        mat[i] = new int[n + 1]();
    }*/

    dfs(graph, vis, 1, mat);

    while (q--)
    {
        int k;
        cin >> k;
        vector<int> vt(k + 1);

        for (int i = 1; i <= k; i++)
        {
            cin >> vt[i];
        }

        int ans = INT_MAX;
        int nodemin;

        for (int i = 1; i <= k; i++)
        {
            if (mat[i][0] < ans)
            {
                ans = mat[0][i];
                nodemin = i;
            }
        }

        for (int i = 1; i <= k; i++)
        {
            if (mat[1][i] > mat[1][nodemin]) // if any node's departure time is greater than the nodemin's departre time then we wont get the ansswer
            {
                nodemin = -1;
                break;
            }
        }

        cout << nodemin << " " << endl;
    }

    return 0;
}