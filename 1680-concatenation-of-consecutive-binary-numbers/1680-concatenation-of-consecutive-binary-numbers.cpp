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
        
        if(b==1){
            return a;
        }
        
        ll res=1LL;
        
        while(b){
            
            if(b%2) res=mul(res,a);
            
            b/=2;
            a=mul(a,a);
            
        }
        
        return res;
        
    }
    
    string binary(int num){
        
        string res="";
        
        while(num>0){
            
            int rem=(num%2);
            
            res+=(char)(rem+'0');
            
            num/=2;
            
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
    
    int concatenatedBinary(int n) {
        
        string str="";
    
        ll product = 1LL;
        
        ll sum = 0LL;
        
        for(int i=n;i>=1;--i){
            
            int msb=log2(i);
            
            for(int bit=0;bit<=msb;bit++){
                
                if((i&(1<<bit))){
                    
                    sum=((sum%M)+(product%M))%M;
                    
                }
                
                product=((2LL%M)*(product%M))%M;
                
            }
            
        }

        
        return sum;
        
    }
};

// 11 100   
    
//     product = 8
    
//     sum = 12