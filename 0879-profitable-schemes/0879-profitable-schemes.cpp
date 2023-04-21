class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    /*
    vector<int>group,profit;
    ll dp[101][101][101];
    
    ll func(int i,int G,int P,int n){
        if(i==n) return P <= 0;
        if(P < 0) P = 0;
        if(dp[i][G][P] != -1LL) return dp[i][G][P];
        ll ways = func(i+1,G,P,n);
        if(G >= group[i]){
            ways += func(i+1,G-group[i],P-profit[i],n);
            ways %= M;
        }
        return dp[i][G][P] = ways;
    } */
    
    
    /*
    int profitableSchemes2(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();
        ll dp[n+1][G+1][P+1];
        memset(dp,0LL,sizeof(dp));
        dp[0][0][0] = 1LL;
        for(int i=0;i<n;i++){
            int grp = group[i];
            int prf = profit[i];
            for(int j=G;j>=0;j--){
                for(int k=P;k>=0;k--){
                    dp[i+1][j][k] += dp[i][j][k];
                    dp[i+1][j][k] %= M;
                    if(j + grp <= G){
                        dp[i+1][j+grp][min(P,prf+k)] += dp[i][j][k];
                        dp[i+1][j+grp][min(P,prf+k)] %= M;
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
    } */
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        
        int n = group.size();
        ll dp[G+1][P+1];
        memset(dp,0LL,sizeof(dp));
        dp[0][0] = 1LL;
        
        for(int i=0;i<n;i++){
            int grp = group[i];
            int prf = profit[i];
            for(int j=G-grp;j>=0;j--){
                for(int k=P;k>=0;k--){
                    dp[j+grp][min(P,k+prf)] += dp[j][k];
                    dp[j+grp][min(P,k+prf)] %= M;
                }
            }
        }
        
        ll sum = 0LL;
        for(int i=0;i<=G;i++){
            sum += dp[i][P];
            sum %= M;
        }
        return sum;
        
    }
    
};