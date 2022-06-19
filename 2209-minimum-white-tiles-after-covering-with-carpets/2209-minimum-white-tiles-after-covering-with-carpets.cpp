class Solution {
public:
    
    int dp[1005][1005];
    
    int func(string &s,int i,int n,int k,int L){
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        int curr=(s[i]-'0');
        
        int ans=curr+func(s,i+1,n,k,L);
        
        if(k>0){
            
            ans=min(ans,func(s,i+L,n,k-1,L));
            
        }
        
        return dp[i][k]=ans;
        
    }
    
    int minimumWhiteTiles(string s, int k, int L) {
        
        int n=s.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(s,0,n,k,L);
        
        return ans;
        
    }
};