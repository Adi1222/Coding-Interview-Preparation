#include <iostream>
#include <deque>
using namespace std;

int main()
{

    int arr[5] = {};
    int k;
    int n = sizeof(arr) / sizeof(arr[0]);
    /*
	
	T.C O(N*K)
	S.C O(1)
	
	int mx;
	
	for(int i = 0; i <= n - k; i++)
	{
		mx = arr[i];
		
		for(int j = 1; j < k; j++)
		{
			if(arr[i + j] > mx)
			{
				mx = arr[i + j];
			}
		}
		
		cout<<mx<<" "<<endl;
	}
	
	*/

    /*
	      |
	      |
	      |   T.C O(N)
	      |   S.C O(k)
	      \/ 
	*/

    deque<int> dq(k);

    int i;

    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for (i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";

        //	I'll try to remove elements which are out of window

        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << arr[dq.front()] << " "; // for the last window

    return 0;
}