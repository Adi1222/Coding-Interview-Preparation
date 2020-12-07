#include <iostream>
#include <queue>
using namespace std;

int dist[1001][1001];
int vis[1001][1001];
int N, M;

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;

    q.push({srcX, srcY});

    dist[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(curX + dx[i], curY + dy[i]))
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];

                dist[newX][newY] = dist[curX][curY] + 1;
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }

    cout << endl
         << "*******ANS********" << endl;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    cin >> N >> M;

    int x, y;

    cin >> x >> y;

    bfs(x, y);

    return 0;
}