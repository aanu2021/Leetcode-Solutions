class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<vector<int>>&events,int i,int k,int n){
        
        if(k==0) return 0;
        if(i==n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = func(events,i+1,k,n);
        int inc = events[i][3];
        ans = max(ans, events[i][2] + func(events,inc,k-1,n));   
        
        return dp[i][k] = ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        dp = vector<vector<int>>(n+1,vector<int>(k+1,0));
        sort(events.begin(),events.end());
        for(int i=0;i<n;i++){
            int inc = n;
            int low = i+1, high = n-1;
            while(low <= high){
                int mid = (low + high)/2;
                if(events[mid][0] > events[i][1]){
                    inc = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            events[i].push_back(inc);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=k;j>=1;j--){
                int inc = events[i][3];
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j] = max(dp[i][j], events[i][2] + dp[inc][j-1]);
            }
        }
        return dp[0][k];
        // int ans = func(events,0,k,n);
        // return ans;
        
    }
};