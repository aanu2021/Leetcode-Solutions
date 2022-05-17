class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>arr;
        
        arr.push_back(1);
        
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        
        arr.push_back(1);
        
        vector<vector<int>>dp(n+3,vector<int>(n+3,0));
        
        for(int i=1;i<=n;i++){
            
            dp[i][i]=(arr[i]*arr[i-1]*arr[i+1]);
            
        }
        
        for(int L=2;L<=n;L++){
            
            for(int i=1;i<=n-L+1;i++){
                
                int j=i+L-1;
                
                for(int k=i;k<=j;k++){
                    
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+(arr[k]*arr[i-1]*arr[j+1]));
                    
                }
                
            }
            
        }
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        return dp[1][n];
        
    }
};