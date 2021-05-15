class Solution {
public:
    
    int solve(vector<int>& nums, int k)
    {
        int ans = 0;
        
        int diff = 0;
        
        vector<int>vt(20005);
        
        int l = 0;
        
        for(int r = 0; r < nums.size(); r++)
        {
            if(vt[nums[r]] == 0)
            {
                diff += 1;
                vt[nums[r]]++;
            }
            else
            {
                vt[nums[r]]++;
            }
            
            if(diff <= k)
            {
                ans += (r - l + 1);
            }
            else
            {
                while(l < nums.size() && l <= r && diff > k)
                {
                    vt[nums[l]]--;
                    
                    if(vt[nums[l]] == 0)
                    {
                        diff -= 1;
                    }
                    
                    l++;
                }
                
                ans += (r - l + 1);
            }
            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums, k) - solve(nums, k - 1);
        
        
    }
};