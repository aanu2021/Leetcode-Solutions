class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        
        return ((a%M)+M)%M;
        
    }
    
    ll add(ll a,ll b){
        
        return mod(mod(a)+mod(b));
        
    }
    
    ll mul(ll a,ll b){
        
        return mod(mod(a)*mod(b));
        
    }
    
    ll modPow(ll a,ll b){
        
        if(b==0) return 1LL;
        if(b==1) return a;
        
        ll res=1LL;
        
        while(b){
            
            if(b%2) res=mul(res,a);
            
            b/=2;
            a=mul(a,a);
            
        }
        
        return res;
        
    }
    
    int concatenatedBinary(int n) {
        
        string str="";
    
        ll sum = 0LL;
        
        ll i = 1LL;
        
        while(i<=n){
            
            int curr_power = 1 + (int) log2(i);
            
            ll curr_value = mul(sum,modPow(2LL,(ll)curr_power));
            
            sum = add((ll)i,curr_value);
            
            i++;
            
        }
        
        return sum;
        
    }
};

//     11 100   
    
//     product = 8
    
//     sum = 12