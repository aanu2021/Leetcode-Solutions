class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    vector<vector<int>>freq;
    vector<vector<ll>>dp;
    
    ll func(string &target,int i,int j,int m,int n){
        if(j==n) return 1LL;
        if(i==m) return 0LL;
        if(dp[i][j] != -1LL) return dp[i][j];
        ll ans = func(target,i+1,j,m,n);
        int pos = target[j]-'a';
        ans += freq[i][pos]*func(target,i+1,j+1,m,n);
        ans %= M;
        return dp[i][j] = ans;
    }
    
    int numWays(vector<string>& words, string target) {
        int m = words[0].length();
        int n = target.length();
        freq.clear();
        dp.clear();
        freq = vector<vector<int>>(m,vector<int>(26,0));
        dp = vector<vector<ll>>(m,vector<ll>(n,-1LL));
        for(int i=0;i<m;i++){
            for(int j=0;j<words.size();j++){
                freq[i][words[j][i]-'a']++;
            }
        }
        ll ans = func(target,0,0,m,n);
        return ans;
    }
};