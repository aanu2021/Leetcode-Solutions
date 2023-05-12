//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    typedef long long int ll;
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
    
    ll fib(ll n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 1;
        ll F[2][2] = {{1,1},{1,0}};
        power(F,n-1);
        return F[0][0];
    }
    
    void power(ll F[2][2],ll n){
        if(n==0 || n==1) return;
        ll M[2][2] = {{1,1},{1,0}};
        power(F,n/2);
        multiply(F,F);
        if(n%2) multiply(F,M);
    }
    
    void multiply(ll F[2][2],ll M[2][2]){
        
        ll x = add(mul(F[0][0],M[0][0]),mul(F[0][1],M[1][0]));
        ll y = add(mul(F[0][0],M[0][1]),mul(F[0][1],M[1][1]));
        ll z = add(mul(F[1][0],M[0][0]),mul(F[1][1],M[1][0]));
        ll w = add(mul(F[1][0],M[0][1]),mul(F[1][1],M[1][1]));
        
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
        
    }
  
    long long int nthFibonacci(long long int n){
        
        return fib(n);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends