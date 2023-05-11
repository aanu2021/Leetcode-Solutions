class Solution {
public:
    
    /*
    
    vector<vector<int>>dp;
    
    int func(vector<int>&nums1,vector<int>&nums2,int i,int j,int m,int n){
        if(i==m || j==n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxLen = 0;
        if(nums1[i]==nums2[j]){
            maxLen = 1 + func(nums1,nums2,i+1,j+1,m,n);
        }
        else{
            maxLen = max(func(nums1,nums2,i+1,j,m,n),func(nums1,nums2,i,j+1,m,n));
        }
        return dp[i][j] = maxLen;
    }
    
    */
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // dp.clear();
        // dp = vector<vector<int>>(m+5,vector<int>(n+5,0));
        
        // Top-Down Approach
        // int ans = func(nums1,nums2,0,0,m,n);
        // return ans;
        
        
        
        // Bottom-Up Approach 
        /* for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0]; */
        
        
        
        // Bottom-Up Approach (Space-Optimized)
        
        vector<int>prev(n+5,0);
        vector<int>curr(n+5,0);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(curr[j+1],prev[j]);
                }
            }
            for(int j=n-1;j>=0;j--){
                prev[j] = curr[j];
            }
        }
        return prev[0];
        
    }
};

