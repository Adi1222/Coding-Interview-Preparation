#include <iostream>
#include <map>
using namespace std;


int main() 
{
	string str = "aabcdabbcdc";
	int n = str.length();
	int k = 3;
	
	int ans = 0;
	map<char,int>mp;
	
	for(int i = 0; i < k; i++)
	{
		mp[str[i]]++;
	}
	
	if(mp.size() == k)
	{
		ans += 1;
	}
	
	for(int i = k; i < n; i++)
	{
		mp[str[i]]++;
		
		mp[str[i - k]]--;
		
		if(mp[str[i - k]] == 0)
		{
			mp.erase(str[i - k]);
		}
		
		if(mp.size() == k)
		{
			ans += 1;
		}
	}
	
	
	cout<<ans<<" "<<endl;
	
	return 0;
}