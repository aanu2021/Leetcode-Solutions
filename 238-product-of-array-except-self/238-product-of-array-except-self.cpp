class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>prefix(n,0);
        
        prefix[0]=nums[0];
        
        for(int i=1;i<n;++i){
            prefix[i]=prefix[i-1]*nums[i];
        }
        
        int prod=1;
        
        for(int i=n-1;i>0;i--){
            
            int curr_prod=prefix[i-1]*prod;
            
            prod*=nums[i];
            
            nums[i]=curr_prod;
            
        }
        
        nums[0]=prod;
        
        return nums;
        
    }
};