class Solution {
public:
    
    typedef long long ll;
    
    ll dp[202][202];
    int price[202][202];
    
    void precompute_pricing(vector<vector<int>>&prices){
        int sz = prices.size();
        for(int i=0;i<sz;++i){
            int h = prices[i][0];
            int w = prices[i][1];
            int p = prices[i][2];
            price[h][w] = max(price[h][w],p);
        }
    }
    
    ll func(int m,int n){
        
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1LL) return dp[m][n];
        
        // Pick the pricing corresponding to current rectangle.
        ll score = price[m][n];
        
        // Break it into two smaller rectangles.
        
        // horizontal cut
        for(int i=1;i<m;i++){
            score = max(score,func(m-i,n) + func(i,n));
        }
        // vertical cut
        for(int i=1;i<n;i++){
            score = max(score,func(m,n-i) + func(m,i));
        }
        
        return dp[m][n] = score;
        
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        memset(dp,-1LL,sizeof(dp));
        memset(price,0,sizeof(price));
        
        precompute_pricing(prices);
        
        ll ans = func(m,n);
        return ans;
    }
};