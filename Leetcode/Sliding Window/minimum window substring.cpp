#include <iostream>
#include <map>
using namespace std;

int main()
{

    string str = "this is a test string";
    string pat = "tist";

    map<char, int> mp;

    for (char c : pat)
    {
        mp[c]++;
    }

    int start;

    int ans = INT_MAX;

    int cnt = pat.length();

    int l = 0, r;

    for (r = 0; r < str.length();)
    {
        if (--mp[str[r++]] >= 0)
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

            if (mp[str[l++]]++ == 0)
            {
                cnt += 1;
            }
        }
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