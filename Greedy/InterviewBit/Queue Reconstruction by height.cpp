/*

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person 
who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

*/

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        const int N = people.size();

        vector<int> pos(N, -1);

        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> ans(N, vector<int>(2, -1));

        for (int i = 0; i < N; i++)
        {
            int cnt = people[i][1];

            for (int j = 0; j < N; j++)
            {
                if (cnt == 0 && pos[j] == -1)
                {
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];

                    pos[j] = 1;

                    break;
                }
                else if (pos[j] == -1 || ans[j][0] >= people[i][0])
                {
                    cnt -= 1;
                }
            }
        }

        return ans;
    }
};