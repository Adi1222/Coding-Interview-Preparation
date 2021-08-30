#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int n, m;
int startX, startY;

char grid[1001][1001];
int monster_time[1001][1001]; // for monsters
int vis_time[1001][1001]; // for user
char direction[1001][1001];

vector<pair<int,int>> monsters;
vector<char>ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool isValid(int i, int j, int time)
{
	if(i < 0 || j < 0 || i >= n || j >= m)
		return false;
		
	if(monster_time[i][j] <= time)
		return false;
		
	return true;
}

bool isValidMonster(int i, int j)
{
	if(i < 0 || j < 0 || i >= n || j >= m)
		return false;
		
	return true;
}

bool isBoundary(int i, int j, int time)
{
	if(!isValid(i, j, time))
		return false;
	
	if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
		return true;
	
	return false;
}


void calculate_monster_time()
{
	queue<pair<int,int>>q;
	
	for(auto i:monsters)
	{
		q.push({i.first, i.second});
		monster_time[i.first][i.second] = 1;
	}
	
	while(!q.empty())
	{
		auto pr = q.front();
		int x = pr.first;
		int y = pr.second;
		int t = monster_time[x][y];
		q.pop();
		
		t++;
		
		for(int i = 0; i < 4; i++)
		{
			int X = x + dx[i];
			int Y = y + dy[i];
			
			if(!monster_time[X][Y] && isValidMonster(X, Y) && grid[X][Y] != '#')
			{
				monster_time[X][Y] = t;
				q.push({X, Y});
			}
			
		}
	}
	
}

bool bfs(int srcX, int srcY)
{
	queue<pair<int,int>>q;
	
	q.push({srcX, srcY});
	
	vis_time[srcX][srcY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		
		//cout<<x<<" "<<y<<endl;
		
		q.pop();
		
		int t = vis_time[x][y];
		
		// for(int i = 0 i < 4; i++)
		// {
		// 	int X = x + dx[i];
		// 	int Y = y + dy[i];
			
		// 	if(is_boundary(X, Y, t))
		// 	{
				
		// 	}
		// }
		
		
		if(isBoundary(x, y, t))
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
		
		t++;
	
		if(isValid(x, y + 1, t) && grid[x][y + 1] != '#' && !vis_time[x][y + 1])
		{
			
			direction[x][y + 1] = 'R';
			q.push({x, y + 1});
			vis_time[x][y + 1] = t;
		}
		
		if(isValid(x + 1, y, t) && grid[x + 1][y] != '#' && !vis_time[x + 1][y])
		{
			direction[x + 1][y] = 'D';
			q.push({x + 1, y});
			vis_time[x + 1][y] = t;
		}

		if(isValid(x, y - 1, t) && grid[x][y - 1] != '#' && !vis_time[x][y - 1])
		{
			direction[x][y - 1] = 'L';
			q.push({x, y - 1});
			vis_time[x][y - 1] = t;
		}

		if(isValid(x - 1, y, t) && grid[x -1][y] != '#' && !vis_time[x - 1][y])
		{
			direction[x - 1][y] = 'U';
			q.push({x - 1, y});
			vis_time[x + 1][y] = t;
		}		
	}
	
	
	return false;
	
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
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
			if(grid[i][j] == 'M')
			{
				monsters.push_back({i, j});
			}
			
		}
	}
	
	
	calculate_monster_time();
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<monster_time[i][j]<<" ";
		}
		
		cout<<endl;
	}*/
	
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