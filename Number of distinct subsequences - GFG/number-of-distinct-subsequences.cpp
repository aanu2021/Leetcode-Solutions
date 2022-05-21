// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

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
  
	int distinctSubsequences(string s)
	{
	    
	    ll n=s.length();
	    
	    map<char,ll>mp;
	    
	    vector<ll>dp(n+1,0LL);
	    
	    dp[0]=1LL;
	    
	    for(ll i=1;i<=n;i++){
	        
	        char ch=s[i-1];
	        
	        dp[i]=mul(2LL,dp[i-1]);
	        
	        if(mp.find(ch)!=mp.end()){
	            
	            
	            ll j=mp[ch];
	            
	            dp[i]=(((dp[i]-dp[j-1])%M)+M)%M;
	            
	            
	        }
	        
	        mp[ch]=i;
	        
	    }
	    
	    return mod(dp[n]);
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends