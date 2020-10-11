/*

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

*/

class Solution
{
public:
    /***************** BFS *****************/

    bool canReach(vector<int> &arr, int start)
    {

        queue<int> q;
        vector<int> vis(arr.size(), 0);

        q.push(start);

        while (!q.empty())
        {
            int ind = q.front();
            q.pop();
            vis[ind] = 1;

            if (arr[ind] == 0)
                return true;

            if (ind + arr[ind] < arr.size() && vis[ind + arr[ind]] == 0)
                q.push(ind + arr[ind]);

            if (ind - arr[ind] >= 0 && vis[ind - arr[ind]] == 0)
                q.push(ind - arr[ind]);
        }

        return false;
    }
};