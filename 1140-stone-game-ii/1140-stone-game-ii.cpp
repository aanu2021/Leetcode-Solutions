class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<int>&piles,int i,int m,int n){
        
        if(i==n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        
        int currmax = -1e9;
        int currsum = 0;
        
        for(int j=0;j<2*m;j++){
            if(i+j >= n) break;
            currsum += piles[i+j];
            currmax = max(currmax,currsum - func(piles,i+j+1,max(j+1,m),n));
        }
        
        return dp[i][m] = currmax;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        
        dp.clear();
        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        
        int maxDiff = func(piles,0,1,n);
        int currSum = accumulate(piles.begin(),piles.end(),0);
        
        return ((currSum + maxDiff)/2);
        
    }
};