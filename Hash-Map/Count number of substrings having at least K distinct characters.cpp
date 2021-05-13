#include <iostream>
#include <map>
using namespace std;

int main()
{
    // your code goes here
    string s = "aabbbcddef";
    int k = 3;

    map<char, int> mp;

    int l = 0;

    int ans = 0;

    for (int r = 0; r < s.length(); r++)
    {
        char ch = s[r];

        mp[ch]++;

        while (mp.size() == k)
        {
            ans += s.length() - r;

            char c = s[l++];

            mp[c]--;

            if (mp[c] == 0)
            {
                mp.erase(c);
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}