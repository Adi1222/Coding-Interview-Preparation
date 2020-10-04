/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        const int N = s.length();
        string ans = "";

        unordered_map<char, int> mp;

        for (char c : s)
        {
            mp[c] += 1;
        }

        vector<int> used(26, 0);

        stack<char> st;

        for (int i = 0; i < N; i++)
        {
            char curr = s[i];
            mp[curr] -= 1;

            if (used[curr - 'a'])
                continue;

            while (!st.empty() && curr < st.top() && mp[st.top()] > 0)
            {
                used[st.top() - 'a'] = 0;
                st.pop();
            }

            used[curr - 'a'] = 1;
            st.push(curr);
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};