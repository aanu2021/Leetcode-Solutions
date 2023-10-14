/* Already available here on leetcode */
/* https://leetcode.com/discuss/interview-question/2775415/SnowFlake-OA */ 

class Solution {
public:
    
    typedef long long ll;
    
    int sufDP[1002];
    
    unordered_map<int,unordered_map<int,int>>dp;
    
    // map<pair<int,int>,int>dp;
    
    ll func(int i,int j,vector<int>&cost,vector<int>&time,int n){
        
        if(dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()){
            return dp[i][j];
        }
        
        if(j + sufDP[i] < 0){
            return INT_MAX;
        }
        if(j >= (n-i)){
            return 0;
        }
        
        ll ans = cost[i] + func(i+1,j+time[i],cost,time,n);
        ans = min(ans,func(i+1,j-1,cost,time,n));
        
        return dp[i][j] = ans;
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();
        
        memset(sufDP,0,sizeof(sufDP));
        
        dp.clear();
        
        for(int i=n-1;i>=0;i--){
            sufDP[i] = sufDP[i+1] + time[i];
        }
        
        ll ans = func(0,0,cost,time,n);
        
        return (int)ans;
        
    }
};