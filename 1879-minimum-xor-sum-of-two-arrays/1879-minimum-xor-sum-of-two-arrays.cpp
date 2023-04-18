class Solution {
public:
    
    vector<int>dp;
    
    int func(vector<int>&A,vector<int>&B,int i,int n,int mask){
        if(i==n) return 0;
        if(dp[mask] != -1) return dp[mask];
        int currMin = INT_MAX;
        for(int j=0;j<n;j++){
            if((mask&(1<<j))==0) continue;
            currMin = min(currMin,(A[i]^B[j]) + func(A,B,i+1,n,(mask^(1<<j))));
        }
        return dp[mask] = currMin;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mask = (1<<n);
        dp = vector<int>(mask,-1);
        int ans = func(nums1,nums2,0,n,mask-1);
        return ans;
    }
};

