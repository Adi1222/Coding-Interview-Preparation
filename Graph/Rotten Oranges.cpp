#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isvalid(vector<vector<int>> &matrix, int x, int y, int r, int c)
{
    if (x >= 0 && x < r && y >= 0 && y < c && matrix[x][y] == 1)
    {
        return true;
    }

    return false;
}

int rotOranges(vector<vector<int>> &matrix, int R, int C)
{
    // Your code goes here

    int cnt = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    q.push({-1, -1}); // pusing the delimiter

    while (!q.empty())
    {
        int flag = 0;

        while (q.front().first != -1 && q.front().second != -1)
        {
            int curx = q.front().first;
            int cury = q.front().second;

            for (int i = 0; i < 4; i++)
            {
                if (isvalid(matrix, curx + dx[i], cury + dy[i], R, C))
                {
                    int newx = curx + dx[i];
                    int newy = curx + dy[i];

                    matrix[newx][newy] = 2;

                    q.push({newx, newy});

                    if (!flag) // incrementing the couhnt for only one time during the whole traversal
                    {
                        flag = 1;
                        cnt += 1;
                    }
                }
            }

            q.pop();
        }

        q.pop(); // removing the delimiter

        if (!q.empty())
        {
            q.push({-1, -1}); // pushing a new delimiter
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> matrix(R);
        for (int i = 0; i < R; ++i)
        {
            matrix[i].resize(C);
            for (int j = 0; j < C; ++j)
                cin >> matrix[i][j];
        }
        cout << rotOranges(matrix, R, C) << endl;
    }
    return 0;
}
