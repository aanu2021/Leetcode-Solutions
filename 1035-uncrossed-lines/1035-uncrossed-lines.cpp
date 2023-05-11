class Solution {
public:
    
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
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        dp.clear();
        dp = vector<vector<int>>(m+1,vector<int>(n+1,-1));
        
        int ans = func(nums1,nums2,0,0,m,n);
        return ans;
    }
};