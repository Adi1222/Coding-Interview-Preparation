#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	
	vector<pair<int,int>> vt = { {1,5}, {1,5}, {1,5}, {2,3}, {2,3} };
	
	const int N = vt.size();
	
	sort(vt.begin(), vt.end());
	
	priority_queue<int, vector<int>, greater<int>> pq; // increasing order of end date
	

	
	int ans = 0;
	int day = vt[0].first; // starts from this day
	
	int j = 0;
	
	
	
	for(int i = 0; i < vt.size(); i++)
	{
		while(j < vt.size() && vt[j].first <= day)
		{
			pq.push(vt[j].second);
			j++;
		}
		
		
		while(!pq.empty() && pq.top() < day) // Removing those jobs whose dealine has past 
			pq.pop();
			
		
		if(pq.empty() == 1)
			continue;
			
		ans += 1;
		
		day += 1;
		pq.pop();
		
	}
	
	
	while(day <= vt[N - 1].second)
	{
		while(j < vt.size() && vt[j].first <= day)
		{
			pq.push(vt[j].second);
			j++;
		}
		
		while(!pq.empty() && pq.top() < day)
		{
			pq.pop();
		}
		
		if(pq.empty() == 1)
		{
			day += 1;
		}
		
		ans += 1;
		day += 1;
		
		pq.pop();
		
	}
	
	cout<<ans<<" "<<endl;
	
	return 0;
}