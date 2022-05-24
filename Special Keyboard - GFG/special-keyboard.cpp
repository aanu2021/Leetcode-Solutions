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
        // code here
        
        vector<ll>dp(n+1,0LL);
        
        for(ll i=1;i<=n;i++){
            
            if(i<=6){
                dp[i]=i;
                continue;
            }
            
            ll curr=0LL;
            
            for(ll j=i-3;j>=1;j--){
                
                curr=max(curr,((i-j-1)*dp[j]));
                
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