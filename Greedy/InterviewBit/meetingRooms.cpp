Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

    Where :

    A[i][0] = start time of the ith meeting.A[i][1] = end time of the ith meeting.Find the minimum number of conference rooms required so that all meetings can be done.

                                                      int Solution::solve(vector<vector<int>> & A)
{

    if (A.size() == 0)
    {
        return 0;
    }

    sort(A.begin(), A.end()); // sorting in increasing order of start time

    priority_queue<int, vector<int>, greater<int>> pq; // for storing end times in increasing order

    pq.push(A[0][1]);

    int rooms = 1;

    for (int i = 1; i < A.size(); i++)
    {

        while (!pq.empty() && A[i][0] >= pq.top()) // while all the prev meetings have ended
        {
            pq.pop();
        }

        pq.push(A[i][1]);

        int meets = pq.size();

        rooms = max(rooms, meets);
    }

    return rooms;
}
