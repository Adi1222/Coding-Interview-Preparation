/*

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

*/

/*



class Solution {
public:
    
    vector<int>dp, visited;
 
    
    // ************* TOP DOWN APPROACH *******************
    
    int findmin(vector<int>& coins, int s)
    {
        
        if(s < 0)
            return -1;
        
        if(s == 0) // 0 coin is required for 0 sum
            return 0;
        
        int &ans = dp[s];
        
        if(visited[s])
            return ans;
        
        visited[s] = 1;
        //ans = INT_MAX;
        
        for(int coin : coins)
        {
            int temp = findmin(coins, s - coin);
            
            if(temp >= 0 && temp < ans)
            {
                ans = 1 + temp;
            }
        }
        
        
        return ans == INT_MAX ? -1 : ans;
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        const int N = coins.size();
        dp.resize(amount + 1, INT_MAX);
        visited.resize(amount + 1, 0);
        
        return findmin(coins, amount);
        
        
    }
};


/***************** BOTTOM UP APPROACH ************
 * 
 * class Solution {
public:
    
    // *************BOTTOM UP APPROACH *******************8
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        const int N = coins.size();
        vector<int>dp, visited;
        dp.resize(amount + 1, amount + 1);
        visited.resize(amount + 1, 0);
        
    
        dp[0] = 0;
        
    
        
        for(int i = 1; i <= amount; i++)
        {
            for(int coin : coins)
            {
                if(coin <= i)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};









*/