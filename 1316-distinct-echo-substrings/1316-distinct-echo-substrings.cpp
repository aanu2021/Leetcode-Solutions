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
    
    ll modPow(ll a,ll b){
        
        if(b==0){
            return 1LL;
        }
        
        else if(b==1){
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
        
        for(ll i=1;i<n;i++){
            powarr[i]=mul(powarr[i-1],26LL);
        }
        
        vector<ll>inv_fact(n+1,0LL);
        
        inv_fact[n-1]=inv(powarr[n-1]);
        
        for(ll i=n-2;i>=0;i--){
            
            inv_fact[i]=mul(inv_fact[i+1],26LL);
            
        }
        
        vector<ll>hash(n+1,0LL);
        
        hash[0]=(ll)(s[0]-'a'+1);
        
        for(ll i=1;i<n;i++){
            
            hash[i]=add(hash[i-1],mul(powarr[i],(ll)(s[i]-'a'+1)));
            
        }
        
        
        set<ll>st;
        
        for(ll len=1;len<=n/2;len++){
            
            ll count=0LL;
            
            for(ll l=0,r=len;r<n;l++,r++){
                
                if(s[l]==s[r]){
                    count++;
                }else{
                    count=0;
                }
                
                if(count==len){
                    
                   // cout<<l<<" "<<r-1<<endl;
                    
                    count--;
                    
                    ll hashval=(r-1>=0 ? hash[r-1] : 0LL)-(l-1>=0 ? hash[l-1] : 0LL);
                    hashval=((hashval%M)+M)%M;
                    
                    hashval=mul(hashval,inv_fact[l]);
                    
                    // hashval=((hashval%M)+M)%M;
                    
                    st.insert(hashval);
                    
                }
                
            }
            
        }
        
        return st.size();
        
    }
};