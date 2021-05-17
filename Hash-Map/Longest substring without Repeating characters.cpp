#include <iostream>
#include <set>
using namespace std;

int main()
{
    string str = "abcabcbb";

    const int n = str.length();

    int l = 0, r;

    int ans = INT_MIN;

    set<char> st;

    for (r = 0; r < n; r++)
    {
        if (st.count(str[r]) == 0)
        {
            st.insert(str[r]);

            ans = max(ans, r - l + 1);
        }
        else
        {
            while (st.count(str[l]) == 1)
            {
                st.erase(str[l++]);
            }
        }
    }

    cout << str.substr(l, ans) << " " << endl;

    return 0;
}