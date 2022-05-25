class Solution {
public:
    bool checkPartitioning(string s) {
        
        int n=s.length();
        
        if(n<3){
            return false;
        }
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=(s[i]==s[i+1] ? true : false);
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
                
            }
            
        }
        
        
        for(int i=1;i<=n-2;i++){
            
            for(int j=n-2;j>=i;j--){
                
                if(dp[i][j]==true && dp[0][i-1]==true && dp[j+1][n-1]==true){
                    return true;
                }
                
            }
            
        }
        
        return false;
        
    }
};