class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    vector<vector<int>>dp;
    
    int func(vector<vector<int>>&freq,string &target,int i,int j,int n,int m){
        if(i==n) return 1;
        if(j==m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        ll ways = func(freq,target,i,j+1,n,m);
        ways += (ll)(freq[j][target[i]-'a'])*(ll)func(freq,target,i+1,j+1,n,m);
        ways %= M;
        return dp[i][j] = (int)ways;
    }
    
    int numWays(vector<string>& words, string target) {
        
        int m = words[0].length();
        int n = target.length();
        
        vector<vector<int>>freq(m,vector<int>(26,0));
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                freq[j][words[i][j]-'a']++;
            }
        }
        
        dp.clear();
        dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        
        int ans = func(freq,target,0,0,n,m);
        return ans;
        
    }
};