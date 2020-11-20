#include <iostream>
#include <vector>
#include <queue>
#define int long long int
using namespace std;

signed main()
{
    vector<int> v = {3, 2, 1, 4, 6, 89, 7, 8, 9, 5};
    int k = 3;
    const int N = v.size();

    priority_queue<int> pq(v.begin(), v.begin() + k); // max heap of size k

    cout << pq.top() << " ";

    for (int i = k; i < N; i++)
    {
        if (v[i - k] == pq.top())
        {
            pq.pop();
        }

        pq.push(v[i]);

        cout << pq.top() << " ";
    }

    return 0;
}