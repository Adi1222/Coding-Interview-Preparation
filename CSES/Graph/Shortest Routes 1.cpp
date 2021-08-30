#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define pii pair<int,int>
#define ll long long
const ll inf = LLONG_MAX;

int dist[100005], vis[100005];
vector<pair<int,int>> adj[100005];

int n, m;


void solve()
{
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	
	pq.push({0, 1}); // dist, node
	
	
	while(!pq.empty())
	{
		int d = pq.top().first;
		int v = pq.top().second;
		
		pq.pop();
		
        if(vis[v])
            continue;

		vis[v] = 1;
		
		
		for(auto x : adj[v])
		{
			int node = x.first;
			int wt = x.second;
			
			if(!vis[node])
			{
		
				if(d + wt < dist[node])
				{
					dist[node] = d + wt;
					pq.push({dist[node], node});
				}		
			}
		
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout<<dist[i]<<" ";
	}
	
}


signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		adj[u].push_back({v, w});
	}
	
	for(int i = 2; i <= n; i++)
	{
		dist[i] = inf;
	}
	
	
	
	solve();
	
	return 0;
}