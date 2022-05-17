class Solution {
public:
    int mergeStones(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if((n-1)%(k-1)!=0){
            return -1;
        }
        
        vector<int>prefix(n,0);
        
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int L=k;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                dp[i][j]=1e9;
                
                for(int m=i;m<j;m+=(k-1)){
                    
                    dp[i][j]=min(dp[i][j],dp[i][m]+dp[m+1][j]);
                    
                }
                
                if((j-i)%(k-1)==0){
                    dp[i][j]+=prefix[j]-(i-1>=0 ? prefix[i-1] : 0);
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};