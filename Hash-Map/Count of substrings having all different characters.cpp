#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    string str = "gffg";
    int n = str.length();

    long long ans = 0;

    int l = 0;
    int r;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (r = 0; r < n;)
    {
        if (cnt[str[r] - 'a'] == 0)
        {
            cnt[str[r] - 'a']++;

            ans += (r - l + 1);
            r++;
        }
        else
        {
            cnt[str[l++] - 'a']--;
        }
    }

    cout << ans << " " << endl;

    return 0;
}