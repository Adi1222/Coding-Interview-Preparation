#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "baaabbabbb";

    if (s.length() < 3)
    {
        cout << s.length() << " ";
        return 0;
    }

    int temp = 2, ans = 2;

    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] != s[i - 1] || s[i] != s[i - 2])
        {
            temp += 1;
        }
        else
        {
            ans = max(ans, temp);
            temp = 2;
        }
    }

    ans = max(ans, temp);

    cout << ans << " ";
    return 0;
}