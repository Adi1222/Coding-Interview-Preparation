#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

//************* Recursive solution ***********/

int knapsack(vector<int> &v, vector<int> &w, int W, int i)
{
    if (W < 0) // base cases
    {
        return -1;
    }
    if (i < 0 || W == 0) // base cases
    {
        return 0;
    }

    int incl = v[i] + knapsack(v, w, W - w[i], i - 1); // if we include the current item and we recursively
    // sole for the remaining items and  we also update the weight

    int excl = knapsack(v, w, W, i - 1); // we do not consider the current item

    return max(incl, excl);
}

int main()
{
    vector<int> v, w;

    // take input v, w

    int W; // Knapsack capacity
    cin >> W;

    int N = v.size();

    cout << "\nAns is :" << knapsack(v, w, W, N - 1) << " ";

    return 0;
}