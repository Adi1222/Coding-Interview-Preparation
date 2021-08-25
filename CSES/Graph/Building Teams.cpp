#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
bool vis[100005];
int color[100005];

int n, m;
 
 
bool isBipartite(int node, int col)
{
	vis[node] = true;
	color[node] = col;
	
	for(int child : adj[node])
	{
		if(!vis[child])
		{
			if(isBipartite(child, col ^ 1) == false) // check if assigning this color leads to bipartite or not (if not return false)
			{
				return false;
			}
		}
		else
		{
			if(color[child] == color[node])
			{
				return false;
			}
		}
	}

	return true;
	
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
			flag = isBipartite(i, 0);
			if(!flag)
				break;
		}
	}
	
	
	if(!flag)
	{
		cout<<"IMPOSSIBLE";
	}
	else
	{
		for(int i = 1; i <= n; i++)
			cout<<color[i] + 1<<" ";
	}
	return 0;
}