/*

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list.
Note:

1. Return 0 if there is no such transformation sequence.
2. All words have the same length.
3. All words contain only lowercase alphabetic characters.
4. You may assume no duplicates in the word list.
5. You may assume beginWord and endWord are non-empty and are not the same.


*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        // ********** The approach is to find the shortest distance from src to destination word.
        // So, we'll use BFS as DFS takes Exponential time

        unordered_set<string> st;

        for (auto word : wordList)
        {
            st.insert(word);
        }

        if (st.count(endWord) == 0) // if endword is not present in the list of words then we'll simply return 0
        {
            return 0;
        }

        queue<pair<string, int>> q; // A queue for implementing BFS

        q.push({beginWord, 1});

        while (!q.empty())
        {
            string cur = q.front().first;
            int ans = q.front().second;

            if (cur.compare(endWord) == 0)
                return q.front().second;

            q.pop();

            for (int i = 0; i < cur.length(); i++)
            {
                string temp = cur;

                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;

                    if (cur.compare(temp) == 0) // is same
                        continue;

                    if (st.count(temp))
                    {
                        q.push({temp, ans + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};