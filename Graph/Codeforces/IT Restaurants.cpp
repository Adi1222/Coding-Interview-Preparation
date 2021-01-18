#include <bits/stdc++.h>
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

int SetBit(int n, int X)
{
    return n | (1 << X);
}
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

int n;

vector<int> adj[5005];
bool pos[5005];
bool local[5005];

int dfs(int src, int par) // returns the subtree size
{
    int s = 1;
    vector<int> sizes;

    for (int child : adj[src])
    {
        if (child == par)
        {
            continue;
        }
        int temp = dfs(child, src); // we'll get the child's subtree size
        s += temp;                  // add it to the parents subtree size
        sizes.push_back(temp);      // all the possible sizes of the current node where cur node is considered as uncolored node
    }

    if (!sizes.empty()) // checking whether the cur node is a leaf node  --- coz we don't have to consider leaf node
    {
        // src is not a leaf

        if (par != 0)
        {
            sizes.push_back(n - s);
        }
        // sizes contains subtree sizes of all adj vertices to src

        /*for(int s: sizes)
		{
			cout<<s<<" ";
		}*/

        // performing knapsack

        for (int i = 1; i <= n; i++)
        {
            local[i] = 0;
        }

        local[0] = 1;

        for (int s : sizes)
        {
            // consider it
            for (int i = n - s; i >= 0; i--)
            {
                if (local[i] == 1)
                {
                    local[i + s] = 1;
                    pos[i + s] = 1;
                }
            }
        }
    }

    return s;
}

void solve()
{
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x, y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    vector<int> ans;

    for (int i = 1; i <= n - 2; i++) // possible values a
    {
        if (pos[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << " " << endl;

    for (int a : ans)
    {
        cout << a << " " << n - 1 - a << " " << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
