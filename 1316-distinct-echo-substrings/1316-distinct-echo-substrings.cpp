class Solution {
public:

    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll fact[2005];
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    ll modPow(ll a,ll b){
        
        if(b==0){
            return 1LL;
        }
        
        if(b==1){
            return a;
        }
        
        ll res=1LL;
        
        while(b){
            
            if(b%2==1){
                res=mul(res,a);
            }
            
            b/=2;
            a=mul(a,a);
            
        }
        
        return res;
        
    }
    
    ll inv(ll a){
        return modPow(a,M-2);
    }
    
   
    int distinctEchoSubstrings(string s) {
        
        ll n=s.length();
        
        vector<ll>powarr(n+1,0LL);
        
        powarr[0]=1LL;
        
        for(ll i=1;i<=n;i++){
            
            powarr[i]=mul(powarr[i-1],26LL);
            
        }
        
        vector<ll>hash(n+2,0LL);
        
        hash[0]=(ll)(s[0]-'a'+1);
        
        for(ll i=1;i<=n;i++){
            
            ll curr=mul(powarr[i],(ll)(s[i]-'a'+1));
            
            hash[i]=add(hash[i-1],curr);
            
        }
        
        
        vector<ll>inv_fact(n+2,0LL);
        
        inv_fact[n]=inv(powarr[n]);
        
        for(ll i=n-1;i>=0;i--){
            
            inv_fact[i]=mul(inv_fact[i+1],26LL);
            
        }
        
        
        unordered_set<ll>S;
        
     
        
        for(ll len=1;len<=n/2;len++){
            
            ll cnt=0LL;
            
            for(ll l=0,r=len;r<n;l++,r++){
                
                if(s[l]==s[r]){
                    cnt++;
                }
                
                else{
                    cnt=0;
                }
                
                if(cnt==len){
                    
                    ll curr=hash[r]-hash[l];
                    
                    curr=mul(curr,inv_fact[l+1]);
                    
                    S.insert(curr);
                    
                    cnt--;
                    
                }
                
            }
            
        }
        
        return S.size();
        
    }
};