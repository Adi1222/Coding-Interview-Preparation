#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() 
{

	vector<int>vt = {1, 0, 0, 1, 0, 1, 1 };
	
	
	const int n = vt.size();
	
	int sz = -1;
	int cur = 0;
	int start;
	
	map<int,int>mp;
	
	mp[0] = -1;
	
	
	for(int i = 0; i < n; i++)
	{
		(vt[i] == 0) ? (cur += -1) : (cur += 1);
		
		if(mp.find(cur) != mp.end())
		{
			int index = mp[cur];
			
			
			if(sz <  i - index)
			{
				sz = i - index;
				start = index;
			}
		}
		else
		{
			mp[cur] = i;
		}
	}
	
	
	if(sz == -1)
	{
		cout<<"NOT POSSIBLE"<<endl;
	}
	else
	{
		++start;
		cout<<start<<" to "<<start + sz - 1<<" "<<endl;
	}
	
	return 0;
}



/*************    O(N^2) Approach                 

int main() 
{

	vector<int>vt = {1, 0, 0, 1, 0, 1, 1 };
	
	
	const int n = vt.size();
	
	int ans = -1;
	int start;
	int sz = -1;
	
	int cur = 0;
	
	// O(N^2) solution 
	
	for(int i = 0; i < n - 1; i++)
	{
		cur = (vt[i] = 0) ? -1 : 1;
		
		for(int j = i + 1; j < n; j++)
		{
			(vt[j] == 0) ? (cur += -1) : (cur += 1);
			
			if(cur == 0 && j - i + 1 > sz)
			{
				sz = j - i + 1;
				start = i;
			}
		}
	}
	
	
	if(sz == -1)
	{
		cout<<"NOT POSSIBLE"<<endl;
	}
	else
	{
		cout<<start<<" to "<<start + sz - 1<<" "<<endl;
	}
	
	return 0;
}

******************/