#include <iostream>
#include <map>
using namespace std;

int main()
{
	int nums[] = {92, 75, 65, 48, 45, 35};
	int k = 10;
	const int n = sizeof(nums) / sizeof(nums[0]);

	if (n & 1) // odd length
	{
		cout << "false"
			 << " ";
		return 0;
	}

	map<int, int> mp;

	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		int rem = nums[i] % k;

		// rem = ((nums[i] % k) + k) %k;

		if (rem < 0)
		{
			rem += k;
		}

		mp[rem]++;

		if (rem == 0)
		{
			if (mp[rem] & 1)
			{
				cout << "false"
					 << " ";
				flag = 1;
				break;
			}

			if (2 * rem == k) // if k = 5 and rem = 5 then k-rem will be 5
			{
				if (mp[rem] & 1) // if odd
				{
					cout << "false"
						 << " ";
					flag = 1;

					break;
				}
			}

			if (mp[rem] != mp[k - rem])
			{
				cout << "false"
					 << " ";
			}
		}
	}

	if (!flag)
		cout << "true"
			 << " ";

	return 0;
}