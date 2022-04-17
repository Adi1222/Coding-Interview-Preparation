#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


int vis[1000];
vector<vector<int>> adj;
stack<int> st;
vector<int> ans;

int dfs(int node) // topo sort
{
    vis[node] = 1;

    for(auto itr : adj[node])
    {
        if(!vis[itr])
        {
            dfs(itr);
        }
    }

    st.push(node);
}

bool check_cycle(int n)
{
    unordered_map<int,int> mp;
    int ind = 0;

    while(!st.empty())
    {
        mp[st.top()] = ind++;

        ans.push_back(st.top());
        
        st.pop();
    }

    for(int i = 0; i < n; i++)
    {
        for(auto it : adj[i])
        {
            if(mp[it]  < mp[i])
            {
                return true; // cycle exits
            }
        }
    }

    return false;

}


int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
        }
    }

    if(check_cycle(n))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}