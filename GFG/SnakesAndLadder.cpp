#include <iostream>
#include <queue>
using namespace std;

int solve(int adj[], int N)
{
    bool *vis = new bool[N];

    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    queue<pair<int, int>> q; // (vertex, dist)

    vis[0] = 1;

    q.push({0, 0});
    int d;

    while (!q.empty())
    {
        auto it = q.front();

        int v = it.first;
        d = it.second;

        if (v == N - 1) // if we reached the destination
        {
            return d;
        }

        q.pop();

        for (int i = v + 1; i <= (v + 6) && i < N; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                int dist = d + 1;
                int ver;

                if (adj[i] != -1)
                {
                    ver = adj[i]; // snake or ladder
                }
                else
                {
                    ver = i; // otherwise next step is one vertex next
                }

                q.push({ver, dist});
            }
        }
    }

    return d;
}

int main()
{

    const int N = 30;
    int moves[N] = {-1};

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << solve(moves, N) << " " << endl;

    return 0;
}