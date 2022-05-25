class Solution {
public:
    int minCut(string s) {
        
        int n=s.length();
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
            }else{
                dp[i][i+1]=false;
            }
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j]){
                    
                    dp[i][j]=dp[i+1][j-1];
                    
                }
                
                else{
                    
                    dp[i][j]=false;
                    
                }
                
            }
            
        }
        
        
        vector<int>cuts(n,INT_MAX);
        
        cuts[0]=0;
        
        for(int i=1;i<n;i++){
            
            if(dp[0][i]==true){
                cuts[i]=0;
                continue;
            }
            
            cuts[i]=INT_MAX;
            
            for(int j=0;j<i;j++){
                
                if(dp[j+1][i]==true){
                    
                    cuts[i]=min(cuts[i],cuts[j]+1);
                    
                }
                
            }
            
        }
        
        return cuts[n-1];
        
    }
};