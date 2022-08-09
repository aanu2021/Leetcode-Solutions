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

        
        vector<ll>curr(n+1,0LL);
        
        
        curr[0]=1LL;

        
        s="*"+s;
        t="*"+t;
        
        
        for(ll i=1;i<=m;++i){
            
            for(ll j=n;j>=1;--j){
                
                if(s[i]==t[j]){
                    
                    curr[j]=curr[j-1]+curr[j];
                    
                }
                
                else{
                    
                    curr[j]=curr[j];
                    
                }
                
            }
        
            
        }
        
        return curr[n];
        
    }
};