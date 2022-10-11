class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3) return false;
        
        vector<int>preMin(n);
        vector<int>suffMax(n);
            
        preMin[0] = nums[0];
        suffMax[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++){
            preMin[i]=min(preMin[i-1],nums[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            suffMax[i]=max(suffMax[i+1],nums[i]);
        }
        
        for(int i=1;i<n-1;i++){
            
            if(preMin[i-1] < nums[i] && nums[i] < suffMax[i+1]){
                
                return true;
                
            }
            
        }
        
        return false;
        
    }
};