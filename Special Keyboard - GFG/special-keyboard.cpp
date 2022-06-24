// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    typedef long long ll;

    long long int optimalKeys(int n){
        
        vector<ll>dp(n+1,0LL);
        
        if(n<=6){
            return n;
        }
        
        for(ll i=1;i<=6;i++){
            dp[i]=i;
        }
        
        for(ll i=7;i<=n;i++){
            
            ll curr=0LL;
            
            for(ll j=i-3;j>=1;j--){
                
                curr=max(curr,dp[j]*(i-j-1));
                
            }
            
            dp[i]=curr;
            
        }
        
        return dp[n];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends