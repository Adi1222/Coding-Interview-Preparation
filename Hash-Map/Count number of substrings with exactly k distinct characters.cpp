#include <iostream>
using namespace std;

int arr[26];

// T.C O(n)

int solve(string s, int n, int k)
{
    memset(arr, 0, sizeof(arr));

    int ans = 0;

    int diff = 0;

    int l = 0, r;

    for (r = 0; r < n; r++)
    {
        if (arr[s[r] - 'a'] == 0)
        {
            diff += 1;
            arr[s[r] - 'a']++;
        }
        else
        {
            arr[s[r] - 'a']++;
        }

        if (diff <= k)
        {
            ans += (r - l + 1);
        }
        else
        {
            while (l < n && l <= r && diff > k)
            {
                arr[s[l] - 'a']--;

                if (arr[s[l] - 'a'] == 0)
                {
                    diff -= 1;
                }

                l++;
            }

            ans += (r - l + 1);
        }
    }

    return ans;
}

int main()
{

    string str = "abcbaa";
    int n = str.length();
    int k = 3;

    cout << solve(str, n, k) - solve(str, n, k - 1);

    return 0;
}