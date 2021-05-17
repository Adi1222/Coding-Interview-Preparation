#include <iostream>
using namespace std;

// T.c O(N)

int main()
{
    string str = "aabbcc";
    int k = 2;
    const int n = str.length();

    int l = 0, r;
    int ans = INT_MIN;
    int start;

    int cnt = 0;

    int freq[256];

    memset(freq, 0, sizeof(freq));

    for (r = 0; r < n; r++)
    {
        if (++freq[str[r] - 'a'] == 1)
        {
            cnt += 1;
        }

        if (cnt == k)
        {
            if (r - l + 1 > ans)
            {
                ans = r - l + 1;
                start = l;
            }
        }

        while (cnt > k && l < r)
        {
            if (--freq[str[l++] - 'a'] == 0)
            {
                cnt -= 1;
            }

            if (cnt == k && (r - l + 1) > ans)
            {
                ans = r - l + 1;
                start = l;
            }
        }
    }

    cout << str.substr(start, ans) << " " << endl;

    return 0;
}