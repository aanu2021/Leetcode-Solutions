class Solution {
public:
    
    const int C = -1000000000;
    
    vector<vector<int>>dp;
    
    int func(vector<int>&nums1,vector<int>&nums2,int i,int j,int m,int n){
        if(i==m || j==n) return 0;
        if(dp[i][j] != C) return dp[i][j];
        int answer = func(nums1,nums2,i+1,j,m,n);
        answer = max(answer, func(nums1,nums2,i,j+1,m,n));
        answer = max(answer, (nums1[i]*nums2[j]) + func(nums1,nums2,i+1,j+1,m,n));
        return dp[i][j] = answer;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int firstMin  = INT_MAX;
        int firstMax  = INT_MIN;
        int secondMin = INT_MAX;
        int secondMax = INT_MIN;
        for(int i=0;i<m;i++){
            firstMin = min(firstMin, nums1[i]);
            firstMax = max(firstMax, nums1[i]);
        }
        for(int i=0;i<n;i++){
            secondMin = min(secondMin, nums2[i]);
            secondMax = max(secondMax, nums2[i]);
        }
        if(firstMax < 0 && secondMin > 0){
            return (firstMax*secondMin);
        }
        if(firstMin > 0 && secondMax < 0){
            return (firstMin*secondMax);
        }
        dp.clear();
        dp = vector<vector<int>>(m,vector<int>(n,C));
        int ans = func(nums1,nums2,0,0,m,n);
        return ans;
    }
};