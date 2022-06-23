class Solution {
public:
    
    typedef long long ll;
    
    long long appealSum(string s) {
        
        ll n=s.length();
        
        ll ans=0LL;
        
        vector<ll>left(n,-1LL);
        
        map<char,ll>mp;
        
        for(ll i=0;i<n;i++){
            
            if(mp.find(s[i])==mp.end()){
                left[i]=-1LL;
            }
            
            else{
                left[i]=mp[s[i]];
            }
            
            mp[s[i]]=i;
            
        }
        
        
        for(ll i=0;i<n;i++){
            
            ll lpart=(i-left[i]);
            ll rpart=(n-i);
            
            ans+=(lpart*rpart);
            
        }
        
        return ans;
        
    }
};