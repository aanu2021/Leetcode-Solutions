//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M) + M)%M;
    }
    ll mul (ll a,ll b){
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
            a = mul(a,a);
        }
        return res;
    }
    
    ll inv(ll a){
        return modPow(a,M-2);
    }
  
    ll nck(ll n,ll k,vector<ll>&fact){
        if(k > n) return 0LL;
        if(k==0) return 1LL;
        return mul(mul(fact[n],inv(fact[n-k])),inv(fact[k]));
    }
    
    bool canFind(ll sum,int C,int D){
        while(sum){
            int rem = (int)(sum%10);
            if(rem != C && rem != D) return false;
            sum/=10;
        }
        return true;
    }
  
    int bestNumbers(int N, int A, int B, int C, int D) {
         
         vector<ll>fact(N+1,0LL);
         fact[0] = 1LL;
         fact[1] = 1LL;
         for(ll i=2;i<=N;i++){
             fact[i] = mul(fact[i-1],i);
         }
         
         ll ans = 0LL;
         for(ll i=0;i<=N;i++){
             ll currSum = (i*A) + (N-i)*B;
             if(canFind(currSum,C,D)){
                 ans = add(ans,nck(N,i,fact));
             }
         }
         
         return ans;
         
    }
};

// N = 2
// A = 1
// B = 2
// C = 3
// D = 5

// 1*1 + 2*1 = 3



// cA = 1
// cB = 1


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends