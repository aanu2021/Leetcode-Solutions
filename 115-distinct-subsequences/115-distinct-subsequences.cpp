class Solution {
public:
    
    typedef long long ll;
    
    ll dp[1002][1002];
    
    ll func(string &s,string &t,ll i,ll j){
        
        if(i<0 && j<0){
            return 1LL;
        }
        
        if(i>=0 && j<0){
            return 1LL;
        }
        
        if(i<0 && j>=0){
            return 0LL;
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        ll num_subseq=0LL;
        
        if(s[i]==t[j]){
            
            num_subseq=func(s,t,i-1,j-1)+func(s,t,i-1,j);
            
        }
        
        else{
            
            num_subseq=func(s,t,i-1,j);
            
        }
        
        return dp[i][j]=num_subseq;
        
    }
    
    int numDistinct(string s, string t) {
        
        ll m=s.length();
        ll n=t.length();
        
        for(ll i=0;i<=m;++i){
            for(ll j=0;j<=n;++j){
                dp[i][j]=-1LL;
            }
        }
        
        ll ans=func(s,t,m-1,n-1);
        
        return ans;
               
    }
};