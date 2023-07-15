class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<vector<int>>&events,int i,int k,int n){
        
        if(k==0) return 0;
        if(i==n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = func(events,i+1,k,n);
        
        int inc = n,low = i+1, high = n-1;
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
        
        ans = max(ans, events[i][2] + func(events,inc,k-1,n));   
        return dp[i][k] = ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        dp = vector<vector<int>>(n,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        int ans = func(events,0,k,n);
        return ans;
        
    }
};