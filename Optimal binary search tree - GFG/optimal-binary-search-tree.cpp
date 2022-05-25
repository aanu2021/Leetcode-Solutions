// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    typedef long long ll;
    
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        
       vector<ll>psum(n+1,0LL);
       
       for(ll i=0;i<n;i++){
           psum[i+1]=psum[i]+(ll)freq[i];
       }
       
       vector<vector<ll>>dp(n+1,vector<ll>(n+1,0LL));
       
       for(ll i=0;i<n;i++){
           dp[i][i]=freq[i];
       }
       
       for(ll L=2;L<=n;L++){
           
           for(ll i=0;i<n-L+1;i++){
               
               ll j=i+L-1;
               
               dp[i][j]=INT_MAX;
               
               ll sum=psum[j+1]-psum[i];
               
               for(ll k=i;k<=j;k++){
                   
                   ll left=(k-1>=i ? dp[i][k-1] : 0LL);
                   ll right=(k+1<=j ? dp[k+1][j] : 0LL);
                   
                   dp[i][j]=min(dp[i][j],left+right+sum);
                   
               }
               
           }
           
       }
       
       return dp[0][n-1];
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends