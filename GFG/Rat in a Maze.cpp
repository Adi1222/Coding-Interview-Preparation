#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

bool isSafe(int i, int j, int m[][MAX], int n, int vis[][MAX])
{
    if (i < 0 || i == n || j < 0 || j == n || vis[i][j] == 1 || m[i][j] == 0)
    {
        return false;
    }

    return true;
}

void solve(int i, int j, int m[][MAX], int n, string &path, vector<string> &possiblePaths, int vis[][MAX])
{
    if (m[i][j] == 0)
    {
        return;
    }

    if (i == n - 1 && j == n - 1)
    {
        possiblePaths.push_back(path);
        return;
    }

    vis[i][j] = 1;

    // trying in all 4 directions

    if (isSafe(i + 1, j, m, n, vis))
    {
        path.push_back('D');
        solve(i + 1, j, m, n, path, possiblePaths, vis);
        path.pop_back(); // if this path doesn't lead us to the ans
    }

    if (isSafe(i - 1, j, m, n, vis))
    {
        path.push_back('U');
        solve(i - 1, j, m, n, path, possiblePaths, vis);
        path.pop_back(); // if this path doesn't lead us to the ans
    }

    if (isSafe(i, j + 1, m, n, vis))
    {
        path.push_back('R');
        solve(i, j + 1, m, n, path, possiblePaths, vis);
        path.pop_back(); // if this path doesn't lead us to the ans
    }

    if (isSafe(i, j - 1, m, n, vis))
    {
        path.push_back('L');
        solve(i, j - 1, m, n, path, possiblePaths, vis);
        path.pop_back(); // if this path doesn't lead us to the ans
    }

    vis[i][j] = 0;
}

vector<string> findPath(int m[MAX][MAX], int n)
{
    // Your code goes here

    vector<string> possiblePaths;
    string path;

    int vis[MAX][MAX];
    memset(vis, 0, sizeof(vis));

    solve(0, 0, m, n, path, possiblePaths, vis);

    sort(possiblePaths.begin(), possiblePaths.end(), [&](string &s1, string &s2) {
        return s1 < s2;
    });

    return possiblePaths;
}