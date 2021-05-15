#include <iostream>
using namespace std;

int main()
{

	int ans = 0;

	int l = 0, r = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (prefix[i] % k != 0)
		{
			l = 0;
			r = i;
			if ((i + 1) > ans)
			{
				ans = i + 1;
				l = 0;
				r = i;
			}
		}

		if (suffix[i] % x != 0)
		{

			if ((n - i) > ans)
			{
				l = i;
				r = n - 1;
				ans = n - i;
			}
		}
	}

	for (int i = l, i <= r; i++)
	{
		cout << vt[i] << " " << endl;
	}

	cout << ans << " " << endl;

	return 0;
}