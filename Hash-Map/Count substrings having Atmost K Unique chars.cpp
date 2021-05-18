#include <iostream>
#include <map>
using namespace std;

// O(N)

int main()
{
    string str = "aabcbcdbca";

    int k = 2;

    const int n = str.length();

    int ans = 0;

    int l = 0, r;

    map<char, int> mp;

    for (r = 0; r < n; r++)
    {
        mp[str[r]]++;

        if (mp.size() <= k)
        {
            ans += (r - l + 1);
        }
        else
        {
            while (l < r && mp.size() > k)
            {
                mp[str[l]]--;

                if (mp[str[l]] == 0)
                {
                    mp.erase(str[l]);
                }

                l++;

                if (mp.size() <= k)
                {
                    ans += (r - l + 1);
                }
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}