class Solution {
public:
    int strangePrinter(string s) {
        
        string res="";
        
        res+=s[0];
        
        for(int i=1;i<s.length();++i){
            if(res.back()!=s[i]){
                res+=s[i];
            }
        }
        
        int n=res.length();
        
        s=res;
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;++i){
            dp[i][i+1]=2;
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                dp[i][j]=1e9;
                
                dp[i][j]=min(dp[i][j],1+dp[i+1][j]);
                
                for(int k=i+1;k<=j;k++){
                    
                   if(s[i]==s[k]){
                       
                       dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                       
                   }
                    
                }
                
                // if(s[i]==s[j]){
                //     dp[i][j]--;
                // }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};