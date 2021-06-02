#include <iostream>
#include <vector>
#include <map>
using namespace std;

// IF you are using map to find min & max T.C --> O(N*llog(N))   S.C --> O(N)

// If you use deque to calculate min & max element  then   T.C ---> O(N)  S.C ---> O(N)

int main()
{

    vector<int> vt = {15, 10, 1, 2, 4, 7, 2};

    const int k = 5;

    const int N = vt.size();

    int ans = 0;

    map<int, int> mp;

    int l = 0, r = 0;

    int start;

    for (r = 0; r < N; r++)
    {
        mp[vt[r]]++;

        int mn = mp.begin()->first;
        int mx = mp.rbegin()->first;

        if (mx - mn <= k)
        {
            if (ans < r - l + 1)
            {
                ans = r - l + 1;
                start = l;
            }
        }
        else
        {
            while (l < r)
            {
                mp[vt[l]]--;

                if (mp[vt[l]] == 0)
                {
                    mp.erase(vt[l]);
                }

                l += 1;

                int mn = mp.begin()->first;
                int mx = mp.rbegin()->first;

                if (mx - mn <= k)
                    break;
            }
        }
    }

    cout << ans << " " << endl;

    return 0;
}

/******************* **************  Deque Solution





class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        const int N = nums.size();
        
        int ans = 0;
        
        
        deque<int>inc;
        deque<int>dec;
        
        int s = 0, e = 0;
        
        while(e < nums.size())
        {
            while(!inc.empty() && nums[inc.back()] >= nums[e])
                inc.pop_back();
            
            inc.push_back(e);
            
            while(!dec.empty() && nums[dec.back()] <= nums[e])
                dec.pop_back();
            
            dec.push_back(e);
            
            
            int diff = nums[dec.front()] - nums[inc.front()];
            
            if(diff > limit)
            {
                s += 1;
                
                if(inc.front() < s) // removing the values that do bot lie in the range
                    inc.pop_front();
                
                if(dec.front() < s)
                    dec.pop_front();
                
                
            }
            else
            {
                ans = max(ans, e - s + 1);
                e += 1;
            }
            
            
        }
        
        
        return ans;
        
        
    }
};






***************************************/