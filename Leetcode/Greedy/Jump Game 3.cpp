class Solution
{
public:
    vector<int> vis;

    bool dfs(vector<int> &arr, int pos)
    {
        if (pos < 0 || pos >= arr.size() || vis[pos])
            return false;

        vis[pos] = 1;

        if (arr[pos] == 0)
            return true;

        return (dfs(arr, pos + arr[pos]) || dfs(arr, pos - arr[pos]));
    }

    bool canReach(vector<int> &arr, int start)
    {

        vis.resize(arr.size(), 0);

        return dfs(arr, start);

        /*queue<int>q;
        vector<int>vis(arr.size(), 0);
        int n = arr.size();
        q.push(start);
        
        
        
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            

            vis[index] = 1;
            
            if(arr[index] == 0)
                return true;
            
            
            
            if(index + arr[index] < n && vis[index + arr[index]] == 0)
                q.push(index + arr[index]);
            

            if(index - arr[index] >= 0   && vis[index - arr[index]] == 0)
                q.push(index - arr[index]);
            
            
        }
        
        return false;*/
    }
};