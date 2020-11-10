#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ar[100001];
int vis[100001], subSize[100001];

int dfs(int node)
{
    vis[node] = 1;
    int cur = 1;

    for (int child : ar[node])
        if (vis[child] == 0)
        {
            cur += dfs(child);
        }

    subSize[node] = cur;
    return cur;
}

int main()
{
    int n, a, b; // n  --> number of nodes

    cin >> n;
    for (int i = 1; i < n; i++) // edges will be n-1
        cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

    //call dfs(1) when 1 is root , if another node is root than pass that node
    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << "The sub tree size of node " << i << " is " << subSize[i] << endl;
    return 0;
}