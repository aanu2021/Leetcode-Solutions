const int MIN = -1000000000;

class Solution {
public:
    
    int maxSatisfaction(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>prev(n+1,MIN);
        vector<int>curr(n+1,MIN);
        
        prev[0] = 0;
        prev[1] = nums[0];
        
        for(int i=1;i<n;i++){
            curr[0] = 0;
            for(int j=1;j<=n;j++){
                curr[j] = max(prev[j],(j*nums[i]) + prev[j-1]);
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        
        int ans = 0;
        for(int i=0;i<=n;i++){
            ans = max(ans,prev[i]);
        }
        return ans;
        
    }
};

/*

base case : curr[0] = 0 [for all 0 <= i < n]
            prev[0] = 0  ,  prev[1] = nums[0] 
            

prev[turn]
curr[turn] = max(prev[turn],(turn*nums[idx]) + prev[turn-1])
swap(prev,curr)    
    
    
*/
    

