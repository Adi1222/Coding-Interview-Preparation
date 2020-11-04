#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod ((int)(1e9 + 7))

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<vector<int>>vt;
    vt.resize(n, vector<int>(2, 0));
    
    for(int i = 0; i < n ; i++)
    {
    	cin >> vt[i][0];
    	cin >> vt[i][1];
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    
    for(int i = 0; i < n; i++)
    {
    	pq.push({vt[i][1], vt[i][0]}); // key will be the end time 
    }
    
    auto itr = pq.top();
    int st = itr.second;
    int end = itr.first;
    pq.pop();
    
    int ans = 1;
    
    
    while(!pq.empty())
    {
    	auto it = pq.top();
    	pq.pop();
    	
    	if(it.second >= end)
    	{
    		ans += 1;
    		end = it.second;
    		
    	}
    }
    
    
    cout<<ans<<" "<<endl;
    
    return 0;
}