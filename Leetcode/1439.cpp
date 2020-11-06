class Solution
{
public:
    /****  T.C is: O(k*n*log(n))   ****/
    // we are making k - 1 iteartions and for each ireation we are pushing n elements in the set (which takes log(n) time)

    int kthSmallest(vector<vector<int>> &mat, int k)
    {

        set<pair<int, vector<int>>> st;

        pair<int, vector<int>> v;

        int m = mat.size();    // rows
        int n = mat[0].size(); // columns

        for (int i = 0; i < m; i++)
        {
            v.second.push_back(0); // index
            v.first += mat[i][0];
        }

        st.insert(v);

        if (k == 1)
            return v.first;

        // loop for k - 1 times

        while (k > 1)
        {
            auto it = st.begin();
            pair<int, vector<int>> p = (*it);
            st.erase(it);

            for (int i = 0; i < m; i++)
            {
                if (p.second[i] + 1 < mat[i].size())
                {
                    pair<int, vector<int>> q = p;

                    q.first += mat[i][q.second[i] + 1] - mat[i][q.second[i]];
                    q.second[i] += 1;
                    st.insert(q);
                }
            }

            k -= 1;
        }

        auto r = st.begin();

        int ans = (*r).first;
        return ans;
    }
};