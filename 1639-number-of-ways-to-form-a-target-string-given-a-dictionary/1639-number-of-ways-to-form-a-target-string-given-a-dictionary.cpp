class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int numWays(vector<string>& words, string target) {
        int m = words[0].length();
        int n = target.length();
        
        vector<vector<int>>freq(m,vector<int>(26,0));
        for(int i=0;i<words[0].length();++i){
            for(int j=0;j<words.size();++j){
                freq[i][words[j][i]-'a']++;
            }
        }
        
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,0LL));
        for(int i=0;i<=m;i++){
            dp[i][n] = 1LL;
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int pos = (target[j]-'a');
                ll ways = dp[i+1][j];
                ways %= M;
                ways += (freq[i][pos]*dp[i+1][j+1]);
                ways %= M;
                dp[i][j] = ways;
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<2;j++){
        //         cout<<freq[i][j]<<" ";
        //     }cout<<"\n";
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        return dp[0][0];
    }
};