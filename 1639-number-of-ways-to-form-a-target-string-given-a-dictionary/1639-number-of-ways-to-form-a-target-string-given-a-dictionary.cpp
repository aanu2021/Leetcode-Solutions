class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll func(vector<vector<int>>&freq,string &target,int i,int j,int m,int n,vector<vector<ll>>&dp){
        if(j==n) return 1LL;
        if(i==m) return 0LL;
        if(dp[i][j] != -1LL) return dp[i][j];
        ll ans = func(freq,target,i+1,j,m,n,dp);
        ans %= M;
        ans += freq[i][target[j]-'a']*func(freq,target,i+1,j+1,m,n,dp);
        ans %= M;
        return dp[i][j] = ans;
    }
    
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].length();
        int len = target.length();
        vector<vector<ll>>dp(m,vector<ll>(len,-1));
        vector<vector<int>>freq(m,vector<int>(26,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                freq[i][words[j][i]-'a']++;
            }
        }
        ll ans = func(freq,target,0,0,m,len,dp);
        return ans;
    }
};