/*

Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

 

*/

/*

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        const int N = A.size();
        
        if(N <= 2)
            return N;
        
        vector<vector<int>>dp;
        
        dp.resize(N, vector<int>(1001,1));
        
        int ans = INT_MIN;
        
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j] + 500;
                
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                
                ans = max(ans, dp[i][diff]);
                
            }
        }
        
        
        return ans;
        
        
        
    }
};

*/