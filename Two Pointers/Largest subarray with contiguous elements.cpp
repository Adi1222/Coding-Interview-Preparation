#include <iostream>
#include <set>
using namespace std;

//T.c O(N^2)

int main()
{

    int arr[] = {10, 12, 12, 10, 10, 11, 10};

    const int n = sizeof(arr) / sizeof(arr[0]);

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        set<int> st;

        int minn = arr[i];
        int maxx = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (st.count(arr[j]) == 1)
            {
                break;
            }

            st.insert(arr[j]);

            maxx = max(maxx, arr[j]);
            minn = min(minn, arr[j]);

            if (maxx - minn == j - i)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}