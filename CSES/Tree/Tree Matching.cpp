#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// DP on Trees 
// T. O(N)

vector<int> adj[200005];
int dp[200001][2];


void solve(int src, int par)
{
	vector<int> prefix, suffix; // for each node we need answer (if the current node is not selected the edge)
	
	
	dp[src][0] = dp[src][1] = 0;
	
	
	bool leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			solve(child, src);
			//cout<<leaf<<" ";
		}
	}
	
	if(leaf)
	{
		return;
	}
	
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			prefix.push_back(std::max(dp[child][0], dp[child][1]));
			suffix.push_back(std::max(dp[child][0], dp[child][1]));
		}
	}
	
	
	for(int i = 1; i < prefix.size(); i++)
	{
		prefix[i] += prefix[i - 1];
	}
	
	for(int i = suffix.size() - 2; i >= 0; i --)
	{
		suffix[i] += suffix[i + 1];
	}
	
	dp[src][0] = suffix[0]; // if i do not include the current node in the edge
	
	int edge = 0;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			int L = (edge == 0) ? 0 : prefix[edge - 1];
			int R = (edge == (int)suffix.size() - 1) ? 0 : suffix[edge + 1];
			
			dp[src][1] = std::max(dp[src][1], 1 + L + R + dp[child][0]);
			
			edge++;
		}
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
	
	
	solve(1, 0);
	
	cout<<std::max(dp[1][0], dp[1][1])<<" ";
	
	
	return 0;
}