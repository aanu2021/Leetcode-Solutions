class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
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
    }
    
    int profitableSchemes(int G, int P, vector<int>& group_, vector<int>& profit_) {
        group = group_;
        profit = profit_;
        int n = group.size();
        memset(dp,-1,sizeof(dp));
        ll ans = func(0,G,P,n);
        return ans;
    }
};