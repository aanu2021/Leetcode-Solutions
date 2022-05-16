class Solution {
public:
    int numDecodings(string s) {
        
        int n=s.length();
        
        if(n==0 || s[0]=='0'){
            return 0;
        }
        
        vector<int>dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        
        s="*"+s;
        
        for(int i=2;i<=n;i++){
            
            int curr=0;
            
            if(s[i]!='0'){
                curr+=dp[i-1];
            }
            
            if((s[i-1]=='1') || (s[i-1]=='2' && s[i]>='0' && s[i]<='6')){
                curr+=dp[i-2];
            }
            
            dp[i]=curr;
            
        }
        
        return dp[n];
        
    }
};