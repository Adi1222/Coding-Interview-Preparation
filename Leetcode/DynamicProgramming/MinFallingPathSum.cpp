// Given a square array of integers A, we want the minimum sum of a falling path through A.

// A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

/*


class Solution {
    const int inf = 1e8;
    vector<vector<int>>dp;
    vector<vector<int>>visited;
public:
    int go(int x, int y, vector<vector<int>>& A)
    {
        
        // consider edge case
        if(x == A.size())
            return 0;
        if(y == A[0].size() || y == -1)
            return inf;
        
        int &ans = dp[x][y];
        if(visited[x][y])
            return ans;
        
        // case 1 : (x+1,y)
        ans = min(ans, A[x][y] + go(x + 1, y, A));
        
        // case 2: (x + 1, y + 1)
        ans = min(ans, A[x][y] + go(x + 1, y + 1, A));
        
        // case 3: (x + 1, y - 1)
        ans = min(ans, A[x][y] + go(x + 1, y - 1, A));
        
        visited[x][y] = 1;
        dp[x][y] = ans;
        
        return ans;
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int rows = A.size();
        int cols = A[0].size();
        int ans = INT_MAX;
        dp.resize(rows, vector<int>(cols, INT_MAX));
        visited.resize(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < cols; i++) 
        {
            // oth row , ith column  as the starting point
            // go(x, y) // minimum pathsum when we start from (x,y)  i.e xth row and yth column and we want to reach the bottom
            // dp[x][y] will store what go(x,y)will return
            
            ans = min(ans, go(0,i,A));
        }
        
        
        return ans;
    }
};


*/