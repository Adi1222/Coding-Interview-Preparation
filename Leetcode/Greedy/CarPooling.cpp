/*

You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

*/

class Solution
{
public:
    static bool mycom(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1]; // sorting in increasing order
    }

    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        const int N = trips.size();
        if (N == 0)
            return true;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //

        sort(trips.begin(), trips.end(), mycom); // we are sorting the trip array based on the starting position (inc order)

        pq.push({trips[0][2], trips[0][0]}); // (destination, num of people);
        int people = trips[0][0];            // initially

        for (int i = 1; i < N; i++)
        {
            // before adding hte no.of people in the current trip to count(people) we need to remove the passengers whoose destination has ended before the starting pos of the current trip

            while (!pq.empty() && pq.top().first <= trips[i][1])
            {
                people -= pq.top().second;
                pq.pop();
            }

            people += trips[i][0]; // add the no. of people in the current trip to count

            if (people > capacity) // checking if the count is greater than the capacity
            {
                return false;
            }

            pq.push(make_pair(trips[i][2], trips[i][0])); //
        }

        return true;
    }
};