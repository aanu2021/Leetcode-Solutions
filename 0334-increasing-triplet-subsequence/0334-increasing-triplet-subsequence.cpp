class Solution {
public:
    bool increasingTriplet2(vector<int>& nums) {
        
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
    
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3) return false;
        
        long long int first = nums[0];
        
        long long int second = 1e10;
        
         for(int i=1;i<n;i++){
            
            if(nums[i]>second){
                return true;
            }
            
            if(nums[i]<first){
                
                first = nums[i];
                
            }
            
            else if(nums[i] > first && nums[i] < second){
                
                second = nums[i];
                
            }
            
        }
        
        return false;
        
    }
    
};