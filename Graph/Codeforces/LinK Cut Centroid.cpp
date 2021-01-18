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

const int N = 1e5 + 5;
vector<int> adj[N];
int leaf;
int n;
int nonleaf;
int centroid;
int sub[N];

int dfs(int src, int par)
{
    int graphsize = n - 1;
    bool iscen = 1;
    int s = 1;
    vector<int> sizes;
    sub[src] = 1;

    for (int child : adj[src])
    {
        if (child == par || child == leaf) // we won't visit leaf
        {
            continue;
        }
        int temp = dfs(child, src);
        s += temp;

        if (temp > graphsize / 2)
        {
            iscen = 0;
        }
    }

    if (par != 0)
    {
        //cout<<src<<"*"<<" "<<endl;
        int parsize = graphsize - s;

        if (parsize > graphsize / 2)
        {
            iscen = false;
        }
    }

    if (iscen == true)
    {
        centroid = src;
    }

    return sub[src] = s;
}

void solve()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // first find leaf

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            leaf = i;
        }
        else
        {
            nonleaf = i;
        }
    }

    //	cout<<nonleaf<<" "<<leaf<<" "<<endl;
    dfs(nonleaf, 0);

    /*for(int i = 1; i <= 6; i++)
	{
		cout<<sub[i]<<" ";
	}*/

    cout << leaf << " " << adj[leaf][0] << " " << endl;
    cout << leaf << " " << centroid << " " << endl;
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
        solve();
    }

    return 0;
}
