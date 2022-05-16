// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
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
    
    long long countWays(int n, int k){
        
        if(n==1){
            return k;
        }
        
        vector<vector<ll>>dp(n+1,vector<ll>(2,0LL));
        
        dp[2][0]=k;
        dp[2][1]=k*(k-1);
        
        for(ll i=3;i<=n;i++){
            
            dp[i][0]=dp[i-1][1];
            dp[i][1]=mul((k-1),add(dp[i-1][0],dp[i-1][1]));
            
        }
        
        ll ans=add(dp[n][0],dp[n][1]);
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends