#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str = "efecfefd";
    int n = str.length();
    int k = 4;

    int freq[26];

    memset(freq, 0, sizeof(freq));

    int distinct = 0;

    int l = 0, r;
    int start;
    int ans = n;

    for (r = 0; r < n; r++)
    {
        if (freq[str[r] - 'a'] == 0)
        {
            distinct += 1;
        }

        freq[str[r] - 'a']++;

        if (distinct == k)
        {
            // removing characters from the beginning which have count more than 1

            while (l < n && l < r && freq[str[l] - 'a'] > 1)
            {
                freq[str[l++] - 'a']--;
            }

            int temp = r - l + 1;
            if (temp < ans)
            {
                ans = temp;
                start = l;
            }
        }

        if (distinct > k)
        {
            while (l < r && distinct > k)
            {
                freq[str[l] - 'a']--;

                if (freq[str[l] - 'a'] == 0)
                {
                    distinct--;
                }

                l++;
            }
        }
    }

    cout << str.substr(start, ans);

    return 0;
}