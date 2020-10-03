/*
Minion Chef likes to eat bananas a lot. There are N piles of bananas in front of Chef; for each i (1 ≤ i ≤ N), the i-th pile contains Ai bananas.

Chef's mother wants her to eat the bananas and be healthy. She has gone to the office right now and will come back in H hours. Chef would like to make sure that she can finish eating all bananas by that time.

Suppose Chef has an eating speed of K bananas per hour. Each hour, she will choose some pile of bananas. If this pile contains at least K bananas, then she will eat K bananas from it. Otherwise, she will simply eat the whole pile (and won't eat any more bananas during this hour).

Chef likes to eat slowly, but still wants to finish eating all the bananas on time. Therefore, she would like to choose the minimum K such that she is able to eat all the bananas in H hours. Help Chef find that value of K.






#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int arr[100005];

bool canEatBananas(int mid, int n, int h)
{
	// 1
	
	int req = 0;
	
	for(int i = 0; i < n; i++)
	{
		req += (int)ceil((double)arr[i]/(double)mid);
	}
	
	if(req <=  h)
	{
		return true;
	}
	
	return false;
	 
}

int BS(int n, int h)
{
	int low = 1; // 1 banana per hour
	int high = arr[n - 1];
	
	while(high - low > 1)
	{
		int mid = low + (high - low) / 2;
		
		if(canEatBananas(mid, n, h))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	if(canEatBananas(low, n, h))
	{
		return low;
	}
	if(canEatBananas(high, n, h))
	{
		return high;
	}
	
	
	return 0;
	
}

int main() 
{
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t, n, h; // n --> no. of piles k ---> no. of hours
	cin>>t;
	
	while(t--)
	{
		cin >> n >> h;
		
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		sort(arr, arr + n);
		
		cout << BS(n, h) << endl;
		
		
		
	}
	
	return 0;
}



*/