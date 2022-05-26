class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        
        vector<vector<int>>dp(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
            dp[i][i]=piles[i];
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=abs(piles[i]-piles[i+1]);
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                int left=piles[i]-dp[i+1][j];
                int right=piles[j]-dp[i][j-1];
                
                dp[i][j]=max(left,right);
                
            }
            
        }
        
        return (dp[0][n-1]>0 ? true : false);
        
    }
};