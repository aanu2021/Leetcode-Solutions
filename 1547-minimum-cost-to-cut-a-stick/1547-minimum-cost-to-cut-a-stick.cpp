class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(),cuts.end());
        
        n=cuts.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                dp[i][j]=1e9;
                
                for(int k=i+1;k<j;k++){
                    
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+(cuts[j]-cuts[i]));
                    
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};