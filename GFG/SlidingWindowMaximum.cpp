#include <iostream>
#include <vector>
#include <queue>
#define int long long int
using namespace std;

// T. C  --> O(n)

signed main()
{
    vector<int> v = {3, 2, 1, 4, 6, 89, 7, 8, 9, 5};
    int k = 3;
    const int N = v.size();

    deque<int> dq(k);

    for (int i = 0; i < k; i++) // processing the first k elements
    {
        while (!dq.empty() && v[i] >= v[dq.back()]) // removing the elements that are not needed
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << v[dq.front()] << " ";

    for (int i = k; i < N; i++)
    {
        // now remove the elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // now we have the elements of current window in the deque but we need to remove the elements that are no longer required

        while (!dq.empty() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        cout << v[dq.front()] << " ";
    }

    return 0;
}