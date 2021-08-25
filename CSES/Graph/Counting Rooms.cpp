#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<char>>grid;

void dfs(int srcx, int srcy)
{
	grid[srcx][srcy] = '#';
	
	for(int i = 0; i < 4; i++)
	{
		int newx = srcx + dx[i];
		int newy = srcy + dy[i];
		
		
		if(newx >= 0 && newy >=0 && newx < grid.size() && newy < grid[0].size() && grid[srcx + dx[i]][srcy + dy[i]] == '.')
		{
			dfs(srcx + dx[i], srcy + dy[i]);	
		}
		
	}
}



int main() 
{
	
	int n, m;
	
	cin >> n >> m;
	

	grid.resize(n, vector<char>(m));
	
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	int ans = 0;
	
		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(grid[i][j] == '.')
			{
				ans += 1;
				dfs(i, j);
			}
		}
	}
	
	cout<<ans<<" ";
	
	
	return 0;
}