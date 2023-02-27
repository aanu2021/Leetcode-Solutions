//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
  typedef long long int ll;
  
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      
      vector<bool>row(n+1,false);
      vector<bool>col(n+1,false);
      vector<ll>ans;
      ll totalCells = (ll)((ll)n*(ll)n);
      ll r = n , c = n;
      
      for(int i=0;i<arr.size();i++){
          int x = arr[i][0];
          int y = arr[i][1];
          if(row[x] == false){
              row[x] = true;
              totalCells -= c;
              r--;
          }
          if(col[y] == false){
              col[y] = true;
              totalCells -= r;
              c--;
          }
          ans.push_back(totalCells);
      }
      
      return ans;
      
      
  }
  
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends