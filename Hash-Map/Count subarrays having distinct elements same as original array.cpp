#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// O(N) T.c

int main()
{

    vector<int> arr = {2, 1, 3, 2, 3};

    const int n = arr.size();

    int l = 0, r;

    set<int> st;

    for (int x : arr)
    {
        st.insert(x);
    }

    int cnt = st.size();
    int ans = 0;

    map<int, int> mp;

    for (r = 0; r < n; r++)
    {
        mp[arr[r]]++;

        if (mp.size() == cnt)
        {
            ans += n - r;

            while (l < r)
            {
                if (--mp[arr[l]] == 0)
                {
                    mp.erase(arr[l]);
                }

                l++;

                if (mp.size() == cnt)
                {
                    ans += n - r;
                }
                else // if size becomes less i.e one unique char got removed
                {
                    break;
                }
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}