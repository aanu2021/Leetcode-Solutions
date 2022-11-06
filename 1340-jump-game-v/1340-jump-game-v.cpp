class Solution {
public:
    
    int func(vector<int>&arr,int i,int n,int d,vector<int>&dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans = 0;
        for(int j=i+1;j<=min(i+d,n-1);j++){
            if(arr[i]>arr[j]){
                ans = max(ans,1+func(arr,j,n,d,dp));
            }else{
                break;
            }
        }
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[i]>arr[j]){
                ans = max(ans,1+func(arr,j,n,d,dp));
            }else{
                break;
            }
        }
        return dp[i] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>dp(n,-1);
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                maxLen = max(maxLen,func(arr,i,n,d,dp));
            }
        }
        return maxLen+1;
    }
};