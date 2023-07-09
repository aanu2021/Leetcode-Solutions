class Solution {
public:
    
    typedef long long ll;
    
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<ll>prefix(n + 1,0LL);
        
        ll currSum = 0;
        
        for(int i=0;i<n;i++){
            
            ll ele = (ll)nums[i];
            
            currSum += prefix[i];
            
            if(ele < currSum){
                return false;
            }
            
            ll reqSum = ele - currSum;
            
            if(reqSum > 0){
                if(i + k - 1 < n){
                    prefix[i] += reqSum;
                    currSum += reqSum;
                    prefix[i+k] -= reqSum;
                }
                else{
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
};



