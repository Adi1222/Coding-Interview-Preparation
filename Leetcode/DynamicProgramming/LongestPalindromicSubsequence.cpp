/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
*/

/*

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>>dp;
        dp.resize(s.length(), vector<int>(s.length(), 0));
        
        for(int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
        }
        
        
        for(int len = 2; len <= s.length(); len++)
        {
            for(int k = 0; k <= s.length() - len; k++)
            {
                int i = k;
                int j = k + len - 1;
                
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j  - 1], dp[i + 1][j]);
                }
                
            }
        }
        
        
        return dp[0][s.length() - 1];
        
        
    }
};


*/