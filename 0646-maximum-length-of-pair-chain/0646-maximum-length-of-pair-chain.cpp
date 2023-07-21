class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        for(int i=n-2;i>=0;i--){
            int low = i+1, high = n-1;
            int inc = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(pairs[mid][0] > pairs[i][1]){
                    inc = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(inc != -1){
                dp[i] = max(dp[i], 1 + dp[inc]);
            }
            dp[i] = max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};

              
    
