#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define mp make_pair
#define pb push_back


const int mod = 1000000007;
vector<int>adj[100001];
int dp[100001];

int n;





void dfs(int node)
{
	dp[node] = 1;
	int mx = 0;
	
	for(int child: adj[node])
	{
		dfs(child);
		mx = max(mx, dp[child]);
	}
	
	dp[node] += mx;
	
}

string convert(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 97 && str[i] <= 122) // small letter
		{
			str[i] = str[i] - 32; // converting it to capital letters
		}
	}
	
	return str;
}





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	unordered_map<string, int>mp;
	
	for(int i = 0; i < n; i++)
	{
		string a, b, c;
		
		cin >> a >> b >> c;
		
		a = convert(a);
		c = convert(c);
		
		
		mp["POLYCARP"] = 1;
		
		if(mp.find(a) == mp.end())
		{
			mp[a] = mp.size() + 1;
		}
		
		adj[mp[c]].push_back(mp[a]);
		
	}
	
	dfs(1);
	
	cout<<dp[1]<<" "<<endl;
	
	
	

    return 0;
}