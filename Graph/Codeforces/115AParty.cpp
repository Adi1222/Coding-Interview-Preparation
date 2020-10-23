#include <iostream>
#include <__msvc_all_public_headers.hpp>
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

int n;
vector<int> vt;
vector<int> cnt;
vector<int> vis;
int ans = INT_MIN;

void bfs(int root)
{
    queue<int> q;

    q.push(root);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (i != cur && vt[i] == cur && !vis[i])
            {
                cnt[i] = cnt[cur] + 1;
                q.push(i);
                ans = max(ans, cnt[i]);
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vt.resize(n + 1);
    cnt.resize(n + 1, 1);
    vis.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> vt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (vt[i] == -1)
        {

            bfs(i);
        }
    }

    if (ans != INT_MIN)
    {
        cout << ans << " " << endl;
    }
    else
    {
        cout << "1"
             << " " << endl;
    }

    return 0;
}