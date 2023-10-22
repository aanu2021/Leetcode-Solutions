//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
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
    ll nck(ll n,ll k){
        ll numerator = 1LL;
        ll denominator = 1LL;
        for(ll i=0;i<k;i++){
            numerator = mul(numerator, (n-i));
            denominator = mul(denominator, (i+1));
        }
        return mul(numerator, inv(denominator));
    }
    
    long long  numberOfPaths(int m, int n)
    {
        return nck(m+n-2,m-1);
    }
};


// (m+n-2)! / (m-1)!(n-1)!
// (m+n-2)*

// (m+n-2)*(m+n-3)*(m+n-4)



//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends