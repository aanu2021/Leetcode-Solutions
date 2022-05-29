class Solution {
public:
    
    typedef long long ll;
        
    ll M=1;
    
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
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        
        M=(ll)modulo;
        
        ll p=(ll)power;
        
        ll target=(ll)hashValue;
        
        ll n=s.length();
        
        
        vector<ll>powarr(k+1,0LL);
        
        powarr[0]=1LL;
        
        
        for(ll i=1;i<=k;i++){
            powarr[i]=mul(powarr[i-1],p);
        }
        
        
        ll hash=0LL;
        
        for(ll i=n-1;i>=n-k;i--){
            
            ll currval=mul(powarr[i-(n-k)],(ll)(s[i]-'a'+1));
            
            hash=add(hash,currval);
            
        }
        
        ll index=-1LL;
        
        if(hash==target){
            index=n-k;
        }
        
        for(ll i=n-k-1;i>=0;i--){
            
            ll include=(ll)(s[i]-'a'+1);
            
            ll exclude=mul((ll)(s[i+k]-'a'+1),powarr[k-1]);
            
            hash-=exclude;
            
            hash=((hash%M)+M)%M;
            
            hash=mul(hash,p);
            
            hash=add(hash,include);
            
            if(hash==target){
                index=i;
            }
            
        }
        
        return s.substr(index,k);
        
    }
};