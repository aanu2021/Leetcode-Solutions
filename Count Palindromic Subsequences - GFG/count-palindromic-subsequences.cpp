// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
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
    
    
    long long int  countPS(string s)
    {
       
       ll n=s.length();
       
       vector<vector<ll>>dp(n+1,vector<ll>(n+1,0LL));
       
       for(ll i=0;i<n;i++){
           dp[i][i]=1LL;
       }
       
       for(ll i=0;i<n-1;i++){
           
           if(s[i]==s[i+1]){
               dp[i][i+1]=3LL;
           }else{
               dp[i][i+1]=2LL;
           }
           
       }
       
       for(ll L=3;L<=n;L++){
           
           for(ll i=0;i<n-L+1;i++){
               
               ll j=i+L-1;
               
               if(s[i]==s[j]){
                   
                   ll curr=1LL+dp[i+1][j]+dp[i][j-1];
                   
                   curr=mod(curr);
                   
                   dp[i][j]=curr;
                   
               }
               
               else{
                   
                   ll curr=add(dp[i+1][j],dp[i][j-1]);
                   
                   curr=((curr-dp[i+1][j-1])%M+M)%M;
                   
                   dp[i][j]=mod(curr);
                   
               }
               
           }
           
       }
       
       return dp[0][n-1];
       
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends