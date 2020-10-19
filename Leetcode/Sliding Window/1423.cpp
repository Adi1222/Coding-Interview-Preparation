/*

There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

*/

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        if (k > cardPoints.size())
            return 0;

        int totalpoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int left = 0, ans = INT_MIN, curr = 0, N = cardPoints.size();

        for (int right = 0; right < cardPoints.size(); right++)
        {
            curr += cardPoints[right];

            if (right - left + 1 == N - k)
            {
                ans = max(ans, totalpoints - curr);
                curr -= cardPoints[left++];
            }
        }

        return ans == INT_MIN ? totalpoints : ans;
    }
};