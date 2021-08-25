#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
bool vis[100005];
int dist[100005];
int parent[100005];

int n, m;
 
bool bfs()
{
	queue<int>q;
	q.push(1);
	vis[1] = true;
	dist[1] = 0;
	
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		if(cur == n)
		{
			return true;
		}
		
		for(int child : adj[cur])
		{
			if(!vis[child])
			{
				vis[child] = 1;
				dist[child] = dist[cur] + 1;
				q.push(child);
				parent[child] = cur;
			}
		}
	}
	
	return false;
}

int main() 
{
	cin >> n >> m;


	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>ans;
	if(bfs())
	{
		cout<<dist[n] + 1<<endl;
		int x = n;
		
		while(x != 1)
		{
			ans.push_back(x);
			x = parent[x];
		}
		
		ans.push_back(1);
		
		reverse(ans.begin(), ans.end());
		
		for(int x : ans)
		{
			cout<<x<<" ";
		}
		
	}
	else
	{
		cout<<"IMPOSSIBLE";
	}
	
	return 0;
}