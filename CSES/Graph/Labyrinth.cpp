#include <iostream>
#include <bits/stdc++.h>
using namespace std;


char grid[1001][1001];
int vis[1001][1001];
char direction[1001][1001];
int n, m;
vector<char>ans;

 
bool isValid(int x , int y)
{
	
	if(x < 1 || x > n || y < 1 || y > m) return false;
	
	if(grid[x][y] == '#' || vis[x][y] == 1) return false;
	
	return true;
}

bool bfs(int srcX, int srcY)
{
	queue<pair<int, int>>q;
	
	q.push({srcX, srcY});
	
	vis[srcX][srcY] = 1;
	
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
	
		q.pop();
		
		
		if(grid[x][y] =='B')
		{
			while(true)
			{
				ans.push_back(direction[x][y]);
				
				if(ans.back() == 'R')
				{
					y--;
				}
				else if(ans.back() == 'L')
				{
					y++;
				}
				else if(ans.back() =='U')
				{
					x++;
				}
				else
				{
					x--;
				}
				
				if(x == srcX && y == srcY)
					break;
				
			}
			
			return true;
		}
		
		
		if(isValid(x, y + 1))
		{
			
			direction[x][y + 1] = 'R';
			q.push({x, y + 1});
			vis[x][y + 1] = 1;
		}
		
		if(isValid(x + 1, y))
		{
			direction[x + 1][y] = 'D';
			q.push({x + 1, y});
			vis[x + 1][y] = 1;
		}

		if(isValid(x, y - 1))
		{
			direction[x][y - 1] = 'L';
			q.push({x, y - 1});
			vis[x][y - 1] = 1;
		}

		if(isValid(x - 1, y))
		{
			direction[x - 1][y] = 'U';
			q.push({x - 1, y});
			vis[x + 1][y] = 1;
		}
		
	}
	
	return false;
}


int main() 
{

	cin >> n >> m;
	
	int startX;
	int startY;
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			
			if(grid[i][j] == 'A')
			{
				startX = i;
				startY = j;
			}
			
		}
	}
	
	
	if(bfs(startX, startY))
	{
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for(int i = ans.size() - 1; i >= 0; i--)
		{
			cout<<ans[i];
		}
	}
	else
	{
		cout<<"NO";
	}
	
	return 0;
}