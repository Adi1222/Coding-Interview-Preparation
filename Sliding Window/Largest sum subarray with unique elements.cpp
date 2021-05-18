#include <iostream>
#include <set>
using namespace std;

//T.c O(N)

int main()
{

    int arr[] = {1, 2, 3, 3, 4, 5, 2, 1};

    const int n = sizeof(arr) / sizeof(arr[0]);

    int l = 0, r;

    int ans = 0;
    int cur = 0;

    set<int> st;

    for (r = 0; r < n;)
    {
        if (st.count(arr[r]) == 0)
        {
            cur += arr[r];

            ans = max(ans, cur);

            st.insert(arr[r]);

            r++;
        }
        else
        {
            while (l < r && st.count(arr[r]) == 1)
            {
                st.erase(arr[l]);

                cur -= arr[l];

                l++;

                if (cur > ans)
                {
                    ans = cur;
                }
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}