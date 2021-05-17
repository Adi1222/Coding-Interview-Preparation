#include <iostream>
using namespace std;

int main()
{

    string str = "aabcbcdbca";
    const int n = str.length();

    int arr[256];

    memset(arr, 0, sizeof(arr));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[str[i] - 'a'] == 0)
        {
            cnt += 1;
        }

        arr[str[i] - 'a']++;
    }

    memset(arr, 0, sizeof(arr));

    int l = 0, r;

    int start;
    int ans = INT_MAX;

    for (r = 0; r < n;)
    {
        if (++arr[str[r++] - 'a'] == 1) // distinct
        {
            cnt -= 1;
        }

        while (l < r && cnt == 0)
        {
            if (r - l < ans)
            {
                ans = r - l;
                start = l;
            }

            if (--arr[str[l++] - 'a'] == 0)
            {
                cnt += 1;
            }
        }

        /*
		   OR the other logic will be
		   
		   if(++arr[str[r++] - 'a'] == 1)
		   {
		   		cnt2 += 1;
		   }
		   
		   if(cnt2 == cnt)
		   {
				if(r - l < ans)
				{
					ans = r - l;
					start = l;
				}
		   		while(arr[str[l] - 'a'] > 1)
		   		{
		   			arr[str[l++] - 'a']--;
		   		}
		   	
		   }
		
		*/
    }

    if (ans == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << str.substr(start, ans) << " " << endl;
    }

    return 0;
}