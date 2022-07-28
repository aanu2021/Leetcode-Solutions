class Solution {
public:
    
    typedef long long ll;
    
    long long appealSum(string s) {
        
        ll n=s.length();
        
        vector<ll>prev(n,-1);
        
        vector<ll>index(26,-1);
        
        for(ll i=0;i<n;++i){
            
            prev[i]=index[s[i]-'a'];
            
            index[s[i]-'a']=i;
            
        }
        
        ll ans=0LL;
        
        for(ll i=0;i<n;++i){
            
            ans+=(i-prev[i])*(n-i);
            
        }
        
        return ans;
        
    }
};