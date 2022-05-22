class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length();
        
        if(n==1){
            return true;
        }
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
            }
        }

        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }
                
            }
            
        }
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];
            }
        }
        
        return ans;
        
    }
};