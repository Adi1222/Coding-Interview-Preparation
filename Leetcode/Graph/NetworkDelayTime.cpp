/*

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

*/

/* The idea is to find the minimum distance from the siurse to any node 
    At the end the answer will be the distance of the farthest node from the source.
  
*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {

        /*************** BFS Approach ****************/

        vector<vector<pair<int, int>>> gr(N + 1); // creating a Adjacency List containing a destination and time

        for (int i = 0; i < times.size(); i++)
        {
            gr[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }

        vector<int> nodetime(N + 1, INT_MAX);

        queue<pair<int, int>> q; // queue consists of node index and min dist from the souce node

        q.push({K, 0}); // pushing the source node index(given) and the dist/time from itself will be 0

        while (!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second; // think of time as of distance for simplicity

            q.pop();

            nodetime[node] = min(time, nodetime[node]);

            for (int i = 0; i < gr[node].size(); i++)
            {
                int tempTime = time + gr[node][i].second;

                if (nodetime[gr[node][i].first] > tempTime)
                {
                    nodetime[gr[node][i].first] = tempTime;
                    q.push(make_pair(gr[node][i].first, tempTime));
                }
            }
        }

        nodetime.erase(nodetime.begin());

        int ans = *max_element(nodetime.begin(), nodetime.end());

        return ans == INT_MAX ? -1 : ans;
    }
};