class Solution
{
public:
    vector<string> ans;

    void all(string cur, int sum, int &n)
    {
        if (sum < 0)
            return;

        if ((int)cur.length() > (2 * n))
        {
            cout << cur << " ";
            return;
        }

        if ((int)cur.length() == 2 * n && sum == 0)
        {
            cout << cur << " ";
            ans.push_back(cur);
            return;
        }

        all(cur + "(", sum + 1, n);

        all(cur + ")", sum - 1, n);

        return;
    }

    vector<string> generateParenthesis(int n)
    {

        string cur = "";

        all(cur, 0, n);

        return ans;
    }
};