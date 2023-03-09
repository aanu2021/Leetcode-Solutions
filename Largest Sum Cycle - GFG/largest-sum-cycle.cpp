//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  
  typedef long long ll;
  
  vector<vector<int>>graph;
  vector<int>vis;
  vector<int>timer;
  vector<ll>sumArr;
  
  void dfs(int u,ll psum,ll &maxSum){
      timer[u] = 1;
      vis[u] = 1;
      sumArr[u] = psum;
      psum += (ll)u;
      for(int v : graph[u]){
          if(vis[v]){
              if(timer[v]){
                  maxSum = max(maxSum,psum - sumArr[v]);
              }
          }
          else{
              dfs(v,psum,maxSum);
          }
      }
      timer[u] = 0;
  }
  
  long long largestSumCycle(int n, vector<int> edges)
  {
      graph.clear();
      vis.clear();
      timer.clear();
      sumArr.clear();
      graph.resize(n);
      vis.resize(n,0);
      timer.resize(n,0);
      sumArr.resize(n,0LL);
      for(int i=0;i<n;i++){
          if(edges[i]==-1) continue;
          graph[i].push_back(edges[i]);
      }
      ll maxSum = -1LL;
      for(int i=0;i<n;i++){
          if(vis[i]) continue;
          dfs(i,0LL,maxSum);
      }
      return maxSum;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends