int Solution::candy(vector<int> &A)
{

    vector<int> vt(A.size(), 1);

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1])
        {
            vt[i] = vt[i - 1] + 1;
        }
    }

    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1] && vt[i] <= vt[i + 1])
        {
            vt[i] = vt[i + 1] + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += vt[i];
    }

    return sum;
}
