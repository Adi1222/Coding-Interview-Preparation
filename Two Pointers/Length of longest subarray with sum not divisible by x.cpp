#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<int> vt = {8, 4, 3, 1, 5, 9, 2};
    int k = 2;
    int n = vt.size();

    int l = -1;
    int r;

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if ((vt[i] % k) != 0)
        {
            if (l == -1)
            {
                l = i;
            }

            r = i; // this will be the rightmost that will change everytime
        }

        cur += vt[i];
    }

    if (cur % k != 0)
    {
        cout << n << " " << endl;
        return 0;
    }
    else if (l == -1)
    {
        cout << "-1" << endl;
        return 0;
    }
    else
    {
        int prefix = l + 1;

        int suffix = n - r;

        cout << n - min(prefix, suffix) << " " << endl;
    }

    return 0;
}