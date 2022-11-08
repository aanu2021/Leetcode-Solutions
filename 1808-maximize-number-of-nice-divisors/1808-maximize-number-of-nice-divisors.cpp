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
        if(b==0) return 1LL;
        if(b==1) return a;
        ll res = 1LL;
        while(b){
            if(b%2) res=mul(res,a);
            b/=2;
            a=mul(a,a);
        }
        return res;
    }
    
    int maxNiceDivisors(int n) {
        if(n==0) return 0;
        if(n<=3) return n;
        if(n%3==0) return modPow(3LL,n/3);
        else if(n%3==1) return mul(4LL,modPow(3LL,(n/3)-1));
        else return mul(2LL,modPow(3LL,n/3));
    }
};