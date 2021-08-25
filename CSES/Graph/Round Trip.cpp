#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
bool vis[100005];
int parent[100005];

int n, m;
 
 
bool dfs_cycle(int node, int par)
{
	vis[node] = 1;
	parent[node] = par;
	
	
	for(int child : adj[node])
	{
		if(!vis[child])
		{
			if(dfs_cycle(child, node) == true)
			{
				return true;
			}
		}
		else
		{
			if(child != par) // back edge present --> there is cycle present
			{
				vector<int>ans;
				
				ans.push_back(node);
				
				int x = parent[node];
				
				while(x != child)
				{
					ans.push_back(x);
					x = parent[x];
				}
				
				ans.push_back(child);
				ans.push_back(node);
				
				cout<<ans.size()<<endl;
				
				for(int x : ans)
				{
					cout<<x<<" ";
				}
				
				return true;
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
	
	bool flag = false;
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			flag = dfs_cycle(i, -1);
			if(flag)
				break;
		}
	}
	
	
	if(flag == false)
	{
		cout<<"IMPOSSIBLE";
	}

	return 0;
}