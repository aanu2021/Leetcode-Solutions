class Solution {
public:
    
    int func(vector<int>&piles,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = max(piles[i] - func(piles,i+1,j,dp) , piles[j] - func(piles,i,j-1,dp));
        
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = func(piles,0,n-1,dp);
        if(ans>0){
            return true;
        }else{
            return false;
        }
    }
};