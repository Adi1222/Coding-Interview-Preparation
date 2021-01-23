class Solution
{
public:
    vector<string> res;
    unordered_set<string> st;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string s, vector<string> &wordDict)
    {

        vector<string> temp;

        if (mp.find(s) != mp.end()) // Memoization
            return mp[s];

        // base case
        if (st.count(s) == 1)
        {
            temp.push_back(s);
        }

        for (int i = 1; i <= s.length(); i++)
        {
            string L = s.substr(0, i);

            if (st.count(L) == 1)
            {
                vector<string> sublist = solve(s.substr(i), wordDict);

                for (auto s : sublist)
                {
                    if (s != "")
                    {
                        string stemp = L + " " + s;
                        temp.push_back(stemp);
                    }
                }
            }
        }

        mp[s] = temp;
        return temp;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {

        // seems like a backtracking Problem

        for (string &s : wordDict)
        {
            st.insert(s);
        }

        return solve(s, wordDict);
    }
};