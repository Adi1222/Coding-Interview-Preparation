int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{

    const int N = A.size();
    int capacity = 0;
    int j;
    for (int i = 0; i < N; i++)
    {
        capacity = 0;

        for (j = i; j < N + i; j++)
        {
            capacity += A[(j % N)] - B[(j % N)];

            if (capacity < 0)
            {
                break;
            }
        }

        if (j == N + i)
        {
            return j - N;
        }
    }

    return -1;
}
