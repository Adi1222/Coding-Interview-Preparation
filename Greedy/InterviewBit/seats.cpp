#define mod 10000003
int Solution::seats(string A)
{

    vector<int> vt;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'x')
        {
            vt.push_back(i);
        }
    }

    int ans = 0;

    int mid = vt.size() / 2;

    int start = 0;
    int end = 0;

    for (int i = 0; i < vt.size(); i++)
    {
        start = vt[i];
        end = vt[mid] - mid + i;

        ans = (ans + abs(end - start)) % mod;
    }

    return ans;
}
