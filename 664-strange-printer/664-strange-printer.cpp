class Solution {
public:
    
    string trimmer(string s){
        
        string res="";
        
        res+=s[0];
        
        for(int i=1;i<s.length();++i){
            
            if(res.back()!=s[i]){
                res+=s[i];
            }
            
        }
        
        return res;
        
    }
    
    int strangePrinter(string s) {
        
        s=trimmer(s);
        
        int n=s.length();
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i=0;i<n;++i){
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;++i){
            dp[i][i+1]=2;
        }
        
        for(int L=3;L<=n;++L){
            
            for(int i=0;i<n-L+1;++i){
                
                int j=i+L-1;
                
                dp[i][j]=1+dp[i+1][j];
                
                for(int k=i+1;k<=j;k++){
                    
                    if(s[i]==s[k]){
                        
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                        
                    }
                    
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};