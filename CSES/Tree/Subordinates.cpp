#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> arr[200005];
int ans[200001];

int dfs(int src)
{
	int cur = 1;
	
	for(int child : arr[src])
	{
		cur += dfs(child);
	}
	
	ans[src] = cur;
	return cur;
}

int main() 
{
	int n;
	cin >> n;
	
	int x;
	
	for(int i = 2; i <= n; i++)
	{
		cin >> x;
		arr[x].push_back(i);
	}
	
	dfs(1);
	
	for(int i = 1; i <= n; i++)
	{
		cout<<ans[i] - 1<<" ";
	}
	
	return 0;
}