class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n=stones.size();
        
        int sum=accumulate(stones.begin(),stones.end(),0);
        
        int target=(sum/2);
        
        vector<bool>dp(target+1,false);
        
        dp[0]=true;
        
        for(int i=0;i<n;++i){
            
            for(int j=target;j>=stones[i];--j){
                
                dp[j]=dp[j] || dp[j-stones[i]];
                
            }
            
        }
        
        int x=0;
        
        for(int i=target;i>=0;i--){
            if(dp[i]){
                x=i;
                break;
            }
        }
        
        int y=sum-x;
        
        return abs(x-y);
        
    }
};