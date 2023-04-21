class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    vector<int>group;
    vector<int>profit;
    vector<vector<vector<ll>>>dp;
    
    ll func(int i,int n,int G,int P){
        if(i==n){
            if(P <= 0) return 1LL;
            else return 0LL;
        }
        if(P < 0) P = 0;
        if(dp[i][G][P] != -1) return dp[i][G][P];
        ll ans = func(i+1,n,G,P);
        if(G >= group[i]){
            ans += func(i+1,n,G-group[i],P-profit[i]);
            ans %= M;
        }
        return dp[i][G][P] = ans;
    }
    
    int profitableSchemes(int G, int P, vector<int>& group_, vector<int>& profit_) {
        int n = group_.size();
        group = group_;
        profit = profit_;
        dp = vector<vector<vector<ll>>>(n+1,vector<vector<ll>>(G+1,vector<ll>(P+1,0LL)));
        dp[0][0][0] = 1LL;
        for(int i=0;i<n;i++){
            int grp = group[i];
            int pro = profit[i];
            for(int g=G;g>=0;g--){
                for(int p=P;p>=0;p--){
                    dp[i+1][g][p] += dp[i][g][p];
                    dp[i+1][g][p] %= M;
                    if(g+grp <= G){
                       dp[i+1][g+grp][min(P,p+pro)] += dp[i][g][p];
                       dp[i+1][g+grp][min(P,p+pro)] %= M;   
                    }
                }
            }
        }
        ll sum = 0LL;
        for(int i=0;i<=G;i++){
            sum += dp[n][i][P];
            sum %= M;
        }
        return sum;
        
    }
};