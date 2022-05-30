class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    int countPalindromicSubsequences(string s) {
        
        ll n=s.length();
        
        vector<vector<ll>>dp(n,vector<ll>(n,0LL));
        
        vector<ll>next(n,-1LL);
        vector<ll>prev(n,-1LL);
        
        map<char,ll>mp;
        
        for(ll i=n-1;i>=0;i--){
            
            char ch=s[i];
            
            if(mp.find(ch)==mp.end()){
                next[i]=-1;
            }else{
                next[i]=mp[ch];
            }
            
            mp[ch]=i;
            
        }
        
        
        mp.clear();
        
        for(ll i=0;i<n;i++){
            
            char ch=s[i];
            
            if(mp.find(ch)==mp.end()){
                prev[i]=-1;
            }else{
                prev[i]=mp[ch];
            }
            
            mp[ch]=i;
            
        }
        
        
        for(ll i=0;i<n;i++){
            dp[i][i]=1LL;
        }
        
        for(ll i=0;i<n-1;i++){
            dp[i][i+1]=2LL;
        }
        
        for(ll L=3;L<=n;L++){
            
            for(ll i=0;i<n-L+1;i++){
                
                ll j=i+L-1;
                
                if(s[i]!=s[j]){
                    
                    dp[i][j]=add(dp[i+1][j],dp[i][j-1]);
                    dp[i][j]=(dp[i][j]-dp[i+1][j-1]+M)%M;
                    dp[i][j]=mod(dp[i][j]);
                    
                }
                
                else if(s[i]==s[j]){
                    
                    ll nc=next[i];
                    ll pc=prev[j];
                    
                    if(nc>pc){
                        dp[i][j]=add(mul(2LL,dp[i+1][j-1]),2LL);
                    }
                    
                    else if(nc==pc){
                        dp[i][j]=add(mul(2LL,dp[i+1][j-1]),1LL);
                    }
                    
                    else{
                        dp[i][j]=mul(2LL,dp[i+1][j-1]);
                        dp[i][j]=(dp[i][j]-dp[nc+1][pc-1]+M)%M;
                    }
                    
                    dp[i][j]=mod(dp[i][j]);
                    
                }
                
            }
            
        }
        
        return mod(dp[0][n-1]);
        
    }
};