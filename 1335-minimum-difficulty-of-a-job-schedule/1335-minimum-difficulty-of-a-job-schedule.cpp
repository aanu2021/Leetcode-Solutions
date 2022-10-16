class Solution {
public:
    
    int func(vector<int>&nums,int i,int n,int k,vector<vector<int>>&dp){
        
        if(i>=n){
            
            if(k==0){
                return 0;
            }
            
            else{
                return 1e9;
            }
            
        }
        
        if(dp[i][k]!=-1){
            
            return dp[i][k];
            
        }
        
        int ans = 1e9;
        
        int currmax = nums[i];
            
        for(int j=i;j<n;j++){
            
            currmax=max(currmax,nums[j]);
            
            if(k>0){
                
                ans = min(ans,currmax + func(nums,j+1,n,k-1,dp));
                
            }
            
        }    
        
        return dp[i][k] = ans;
        
    }
    
    int minDifficulty(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));
        
        int currmax = 0;
        
        for(int i=0;i<n;i++){
            
            currmax = max(currmax,nums[i]);
            
            dp[i][1] = currmax;
            
        }
        
        for(int i=0;i<n;i++){
            
            for(int day=2;day<=k;day++){
                
                int ans = 1e9;
                
                int currmax = nums[i];
                
                for(int j=i;j>=0;j--){
                    
                    currmax = max(currmax,nums[j]);
                    
                int prev = (j-1>=0 ? dp[j-1][day-1] : 1e9);
                    
                    ans = min(ans,currmax + prev);
                    
                }
                
                dp[i][day] = ans;
                
            }
            
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=k;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
        
        if(dp[n-1][k]>=1e9) return -1;
        
        return dp[n-1][k];
        
    }
};


// dp[i][k] 

// i-th days
// k of powers