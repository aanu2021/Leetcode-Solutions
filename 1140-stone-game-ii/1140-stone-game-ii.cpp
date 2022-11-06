class Solution {
public:
    
    int func(vector<int>&piles,int i,int m,vector<vector<int>>&dp){
        if(i==piles.size()) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans = -1e9;
        int sum = 0;
        for(int j=0;j<2*m;j++){
            if(i+j>=piles.size()) break;
            sum+=piles[i+j];
            ans = max(ans,sum-func(piles,i+j+1,max(j+1,m),dp));
        }
        return dp[i][m] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int diff = func(piles,0,1,dp);
        //cout<<diff<<"\n";
        int sum = accumulate(piles.begin(),piles.end(),0);
        return (sum+diff)/2;
    }
};