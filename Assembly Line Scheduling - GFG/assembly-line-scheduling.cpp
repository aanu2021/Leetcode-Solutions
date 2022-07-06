// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  
  typedef long long ll;
  
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      
      ll n=a[0].size();
      
      vector<vector<ll>>dp(2,vector<ll>(n));
      
      dp[0][0]=e[0]+a[0][0];
      dp[1][0]=e[1]+a[1][0];
      
      for(ll i=1;i<n;++i){
          
          dp[0][i]=min(dp[0][i-1]+a[0][i],dp[1][i-1]+a[0][i]+T[1][i]);
          
          dp[1][i]=min(dp[1][i-1]+a[1][i],dp[0][i-1]+a[1][i]+T[0][i]);
          
      }
      
      return min(dp[0][n-1]+x[0],dp[1][n-1]+x[1]);
      
  }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends