class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
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
                
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                }
                
            }
            
        }
        
        int maxLen=0,startidx=-1;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        startidx=i;
                    }
                }
            }
        }
        
        return s.substr(startidx,maxLen);
        
    }
};