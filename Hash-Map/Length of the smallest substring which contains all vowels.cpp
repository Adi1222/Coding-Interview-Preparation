#include <iostream>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main()
{
    string str = "aaeebbeaccaaoiuooooooooiuu";
    int n = str.length();

    int ans = n;

    int freq[26];
    memset(freq, 0, sizeof(freq));

    int l = 0, r;
    int cnt = 0;

    for (r = 0; r < n; r++)
    {
        if (isVowel(str[r]) && freq[str[r] - 'a'] == 0)
        {
            cnt += 1;
        }

        freq[str[r] - 'a']++;

        if (cnt == 5)
        {
            while (l < r && ((isVowel(str[l]) && freq[str[l] - 'a'] > 1) || (!isVowel(str[l]))))
            {
                freq[str[l++] - 'a']--;

                int temp = r - l + 1;

                if (temp < ans)
                {
                    ans = temp;
                }
            }
        }
    }

    if (ans == n)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << " " << endl;
    }

    return 0;
}