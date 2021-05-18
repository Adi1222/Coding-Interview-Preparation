#include <iostream>
#include <map>
using namespace std;

//T.c O(N)

int main()
{

    string str = "aabcbcdbca";

    int n = str.length();

    int k = 2;

    int l = 0, r;

    int start;

    int ans = 0;

    map<char, int> mp;

    for (r = 0; r < n; r++)
    {
        mp[str[r]]++;

        if (mp.size() <= k)
        {
            if (r - l + 1 > ans)
            {
                ans = r - l + 1;
                start = l;
            }
        }
        else
        {
            while (l < r && mp.size() > k)
            {
                if (--mp[str[l]] == 0)
                {
                    mp.erase(str[l]);
                }

                l++;
            }
        }
    }

    cout << str.substr(start, ans) << " " << endl;

    return 0;
}