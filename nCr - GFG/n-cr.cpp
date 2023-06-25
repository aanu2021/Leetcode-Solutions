//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
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
            if(b%2) res = mul(res,a);
            b/=2;
            a=mul(a,a);
        }
        return res;
    }
    ll inv(ll a){
        return modPow(a,M-2);
    }
    ll fact[2002];
    void factFind(){
        memset(fact,0LL,sizeof(fact));
        fact[0] = 1LL;
        for(int i=1;i<=2000;i++){
            fact[i] = mul(fact[i-1],(ll)i);
        }
    }
    ll nck(ll n,ll k){
        if(n < k) return 0LL;
        if(k==0) return 1LL;
        if(n==k) return 1LL;
        return mul(mul(fact[n],inv(fact[n-k])),inv(fact[k]));
    }

    int nCr(int n, int r){
        
        factFind();
        
        ll ans = nck((ll)n,(ll)r);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends