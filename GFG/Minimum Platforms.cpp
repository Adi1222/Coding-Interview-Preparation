#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{

    vector<pair<int, int>> vt = {{900, 910}, {940, 1200}, {950, 1120}, {1100, 1130}, {1500, 1900}, {1800, 2000}};

    int result = 1;

    const int N = vt.size();

    /* O(N*N) solution
	
	for(int i = 0; i < vt.size(); i++)
	{
		int plat_needed = 1;
		
		for(int j = i + 1; j < vt.size(); j++)
		{
			// checking for overlap
			
			if((vt[j].first <= vt[i].second && vt[j].first >= vt[i].first ) || (vt[j].first <= vt[i].first && vt[j].second >= vt[i].first) )
			{
				plat_needed += 1;
			}
			
		}
		
		result = max(result, plat_needed);
	}
	
	
	cout<<result<<" "<<endl;*/

    /*

     O(Nlog(N)) solution	
	
	sort(vt.begin(), vt.end());
	
	sort(vt.begin(), vt.end(), [&](pair<int,int>& p1, pair<int,int>& p2){ return p1.second < p2.second ;});
	
	
	int plat_needed = 1;
	int i = 1, j = 0;
	
	
	while(i < N && j < N)
	{
		if (vt[i].first <= vt[j].second)
		{
			plat_needed += 1;
			i++;
		}
		
		else if (vt[i].first > vt[j].second)
		{
			plat_needed -= 1;
			j += 1;
		}
		
		result = max(result, plat_needed);
	}
	
	
	cout<<result<<" "<<endl;*/

    // Using Multi-map --> stores keys in ascending order

    multimap<int, char> mp;

    for (int i = 0; i < N; i++)
    {
        mp.insert(make_pair(vt[i].first, 'a'));
        mp.insert(make_pair(vt[i].second, 'd'));
    }

    int plat_needed = 1;
    auto it = mp.begin();
    ++it;

    for (; it != mp.end(); it++)
    {
        if (it->second == 'a') // or (*it).second
        {
            plat_needed += 1;
        }
        else
        {
            plat_needed -= 1;
        }

        result = max(result, plat_needed);
    }

    cout << result << " ";

    return 0;
}