#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dp[200005];
int ht[200005]; /// max down height of each node


void findHeight(int src, int par)
{
	int mx = 0;
	ht[src] = 0;
	
	bool leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			findHeight(child, src);
			mx = max(mx, ht[child]);
		}
	}
	
	if(leaf)
	{
		ht[src] = mx; // it's anyways 0
	}
	else
	{
		ht[src] = 1 + mx;	
	}
	
}


// or 
int calculateHeight(int src, int par)
{
	int mx = 0;
	ht[src] = 0;
	
	bool leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			mx = max(mx, calculateHeight(child, src));
		}
	}
	
	return ht[src] = (leaf == 1) ? 0 : 1 + mx;
	
}


void solve(int src, int par)
{
	
	vector<int>temp;
	
	dp[src] = ht[src];
	
	bool leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			solve(child, src);
			temp.push_back(ht[child]);
			dp[src] = max(dp[src], dp[child]);

		}
	}
	
	if(leaf)
	{
		return;
	}
	
	
	// for(int child : adj[src])
	// {
	// 	if(child!=par)
	// 	{
	// 		temp.push_back(ht[child]);
	// 		dp[src] = max(dp[src], dp[child]);
	// 	}
	// }
	
	
	sort(temp.begin(), temp.end(), greater<int>());
	int sz = temp.size();
	
	if(temp.size() == 1)
	{
		dp[src] = max(dp[src], 1 + temp[0]);
	}
	else if(temp.size() == 2)
	{
		dp[src] = max(dp[src], 2 + temp[sz - 1] + temp[sz - 2]);
	}

}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	
	cin >> n;
	
	for(int i = 2; i <= n; i++)
	{
		int u, v;
		
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	calculateHeight(1, 0);
	
	solve(1, 0);
	
	cout<<dp[1]<<" ";
	
	return 0;
}