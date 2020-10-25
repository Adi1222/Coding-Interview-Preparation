/*

1466. Reorder Routes to Make All Paths Lead to the City Zero

There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach the city 0 after reorder.

*/

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<int> graph[n];
        set<pair<int, int>> st;
        vector<int> vis(50005, 0);

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u); // creating a bi directional graph

            st.insert({connections[i][0], connections[i][1]});
        }

        queue<int> q;
        q.push(0);
        int ans = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            vis[cur] = 1;

            for (int i = 0; i < graph[cur].size(); i++)
            {
                int child = graph[cur][i];

                if (!vis[child])
                {
                    if (st.count({cur, child}))
                    {
                        ans += 1;
                    }

                    q.push(child);
                }
            }
        }

        return ans;
    }
};