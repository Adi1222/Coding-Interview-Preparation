#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/************ T.C O(n*2 log(k)) *********/
/********** S. C O(k) ********/

int main()
{

    vector<int> a = {10, -10, 20, -40};
    int n = a.size();
    int k = 6;

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    prefix[1] = a[0];

    for (int i = 2; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int t = prefix[j] - prefix[i - 1];

            if (pq.empty())
            {
                pq.push(t);
            }
            else
            {
                if (t > pq.top())
                {
                    pq.pop();
                    pq.push(t);
                }
            }
        }
    }

    cout << pq.top() << " ";

    return 0;
}