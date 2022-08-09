class Solution {
public:
    
    /*
    
    1-D DP Optimization
    
    Time Complexity  : O(M*N)
    Space Complexity : O(N)
    
    */
    
    typedef unsigned long long ll;
    
    int numDistinct(string s, string t) {
        
        ll m=s.length();
        ll n=t.length();
        
        vector<ll>prev(n+1,0LL);
        vector<ll>curr(n+1,0LL);
        
        prev[0]=1LL;
        curr[0]=1LL;
        
        
        s="*"+s;
        t="*"+t;
        
        for(ll i=1;i<=m;++i){
            
            for(ll j=1;j<=n;++j){
                
                if(s[i]==t[j]){
                    
                    curr[j]=prev[j-1]+prev[j];
                    
                }
                
                else{
                    
                    curr[j]=prev[j];
                    
                }
                
            }
            
            prev=curr;
            
        }
        
        return prev[n];
        
    }
};