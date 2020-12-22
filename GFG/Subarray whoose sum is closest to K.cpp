#include <iostream>
#include <vector>
#include <set>
using namespace std;

// T.C O(Nlog(N))

int main()
{

    int a[] = {2, 2, -1, 5, -3, -2};

    int n = sizeof(a) / sizeof(a[0]);

    int k = 7;

    set<int> s;

    int prefix = a[0];

    s.insert(a[0]);

    int mini = abs(a[0] - k); // this is the minimum difference between the number and k

    int ans = prefix;

    for (int i = 1; i < n; i++)
    {

        prefix += a[i];

        auto it = s.lower_bound(prefix - k);

        if (it == s.begin())
        {
            int temp = *it;

            if (abs((prefix - temp) - k) < mini)
            {
                mini = abs((prefix - temp) - k);

                ans = prefix - temp;
            }
        }

        else if (it != s.end())
        {
            int temp = *it;

            if (abs(prefix - temp) - k < mini)
            {
                mini = abs((prefix - temp) - k);

                ans = prefix - temp;
            }

            it--;

            temp = *it;

            if (abs(prefix - temp) - k < mini)
            {
                mini = abs((prefix - temp) - k);

                ans = prefix - temp;
            }
        }
        else
        {
            if (abs(prefix - k) < mini)
            {
                mini = abs(prefix - k);

                ans = prefix;
            }
        }

        s.insert(prefix);
    }

    cout << ans << " " << endl;

    return 0;
}