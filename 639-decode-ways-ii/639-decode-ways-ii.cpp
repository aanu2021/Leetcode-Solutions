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
    
    int func(string &s,int n){
        
        vector<ll>dp(n+1);
        
        dp[0] = 1LL;  // Trivial Case
        
        // Base Case
        
        if(s[0]=='*'){
            dp[1] = 9LL;
        }else{
            dp[1] = 1LL;
        }
        
        s = "*" + s;
        
        // Recurrence and Transitions
        
        for(int i=2;i<=n;++i){
            
            char prev = s[i-1];
            char curr = s[i];
            
            if(curr == '*'){
                
                dp[i] = add(dp[i],mul(9LL,dp[i-1]));
                
            }else{
                
                if(curr > '0'){
                    
                    dp[i] = add(dp[i],dp[i-1]);
                    
                }
                
            }
            
            if(prev == '1'){
                
                if(curr == '*'){
                    
                    dp[i] = add(dp[i],mul(9LL,dp[i-2]));
                    
                }
                
                else{
                    
                    dp[i] = add(dp[i],dp[i-2]);
                    
                }
                
            }
            
            if(prev == '2'){
                
                if(curr == '*'){
                    
                    dp[i] = add(dp[i],mul(6LL,dp[i-2]));
                    
                }
                
                else if(curr <= '6'){
                    
                    dp[i] = add(dp[i],dp[i-2]);
                    
                }
                
            }
            
            if(prev == '*'){
                
                if(curr == '*'){
                    
                    dp[i] = add(dp[i],mul(15LL,dp[i-2]));
                    
                }
                
                else{
                    
                    if(curr <= '6'){
                        
                        dp[i] = add(dp[i],mul(2LL,dp[i-2]));
                        
                    }
                    
                    else{
                        
                        dp[i] = add(dp[i],dp[i-2]);
                        
                    }
                    
                }
                
            }
            
        }
        
        return dp[n];
        
    }
    
    int numDecodings(string s) {
        
        int n=s.length();
        
        if(n==0 || s[0]=='0'){
            return 0;
        }
        
        int ans = func(s,n);
        
        return ans;
        
    }
};