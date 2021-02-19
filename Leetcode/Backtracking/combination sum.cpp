/*
    Aditya Chavan
*/

class Solution {
public:
    
    /*
        T.C: 2^target x K
    
    */
    
    vector<vector<int>>ans;
    
    void solve(vector<int>& arr, int idx, int target,vector<int>& temp)
    {
        // base case
        if(target < 0 || idx >= arr.size())
            return;
        
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[idx]);
        solve(arr, idx, target - arr[idx], temp);
        temp.pop_back();
        
        // i do not pick the element
        solve(arr, idx + 1, target, temp);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        solve(candidates, 0, target, temp);
        return ans;
    }
};