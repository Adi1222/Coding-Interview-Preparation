#include <iostream>
#include <vector>
using namespace std;

int main() 
{

	vector<int>vt = { -1, 3, -1, 8, 5, 4 };
	
	int k  = 3;
	
	const int N = vt.size();
	
	sort(vt.begin(), vt.end());
	
	
	int ans = vt[N - 1] - vt[0];
	
	for(int i = 0, j = N - k - 1; j < N; )
	{
		ans = min(ans, vt[j] - vt[i]);
		
		i++;
		j++;
	}
	
	
	cout<<ans<<" "<<endl;
	
	
	return 0;
}