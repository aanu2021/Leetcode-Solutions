class Solution {
public:
    int maxProduct(string s) {
        
        int n=s.length();
        
        int dp[1<<n];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<(1<<n);i++){
            
            string str="";
            
            for(int j=0;j<n;j++){
                
                if((i&(1<<j))!=0){
                    str+=s[j];
                }
                
            }
            
            string rev=str;
            
            reverse(rev.begin(),rev.end());
            
            if(str==rev){
                dp[i]=str.length();
            }else{
                dp[i]=0;
            }
            
        }
        
        
        int maxLen=0;
        
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<(1<<n);j++){
                if((i&j)!=0){
                    continue;
                }
                maxLen=max(maxLen,dp[i]*dp[j]);
            }
        }
        
        return maxLen;
        
    }
};