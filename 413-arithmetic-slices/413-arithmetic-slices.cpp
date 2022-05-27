class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n<3){
            return 0;
        }
        
        vector<int>dp(n+1,0);
        
        int diff=nums[1]-nums[0];
        
        for(int i=2;i<n;i++){
            
            int curr=nums[i]-nums[i-1];
            
            if(curr==diff){
                dp[i]=dp[i-1]+1;
            }
            
            else{
                dp[i]=0;
                diff=nums[i]-nums[i-1];
            }
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=dp[i];
        }
        
        return ans;
        
    }
};