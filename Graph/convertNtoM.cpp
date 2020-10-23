/*

Given n and m find min no . of steps to convert n to m if :
option1 1: multiply n by 2
option 2: subtract 1 from n

*/

#include <iostream>
#include <__msvc_all_public_headers.hpp>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);
    int level = 0, ans = -1;
    vector<int> vis(200001, 0);

    while (!q.empty())
    {

        int cnt = q.size();
        int cur = q.front();
        q.pop();
        vis[cur] = 1;

        for (int i = 0; i < cnt; i++)
        {
            if (cur == m)
            {
                ans = level;
                break;
            }
            if (cur < m && !vis[cur])
            {
                q.push(2 * cur);
            }
            if (cur > 0 && !vis[cur])
            {
                q.push(cur - 1);
            }
        }

        if (ans != -1)
        {
            break;
        }
        level += 1;
    }

    cout << ans << " " << endl;
}