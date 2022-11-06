class Solution {
public:
    map<int,int>dp;
    int func(vector<int>&arr,int i,int n){
        if(i<0 || i>=n){
            return 0;
        }
        if(arr[i]==0){
            return dp[i] = 1;
        }
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        dp[i] = 0;
        dp[i] = func(arr,i+arr[i],n) || func(arr,i-arr[i],n);
        return dp[i];
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return func(arr,start,n);
    }
};