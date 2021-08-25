#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
bool vis[100005];
 

void dfs(int i)
{
	vis[i] = 1;
	
	for(int child : adj[i])
	{
		if(!vis[child])
			dfs(child);
	}
}


int main() 
{
	int n, m;
	
	
	
	cin >> n >> m;
	
	
	vector<int>ans;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			ans.push_back(i);
		}
	}
	
	
	cout<<ans.size() - 1<<endl;
	
	for(int i = 0; i < ans.size() - 1; i++)
	{
		cout<<ans[i]<<" "<<ans[i + 1]<<endl;
	}
	
	return 0;
}