//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU{
  
  public:
  
  vector<int>Parent;
  vector<int>Rank;
  
  DSU(int n){
      Parent.resize(n);
      Rank.resize(n);
      for(int i=0;i<n;i++){
          Parent[i] = i;
          Rank[i] = 1;
      }
  }
  
  int find(int x){
      if(Parent[x]==x) return x;
      return Parent[x] = find(Parent[x]);
  }
  
  void Union(int x,int y){
      int lx = find(x);
      int ly = find(y);
      if(lx != ly){
          if(Rank[lx] < Rank[ly]){
              Parent[lx] = ly;
          }
          else{
              Parent[ly] = lx;
              if(Rank[lx] == Rank[ly]){
                  Rank[lx]++;
              }
          }
      }
  }
    
};


class Solution {
  public:
  
    int Solve(int n, vector<vector<int>>& edges) {
        
        DSU obj(n);
        
        int additional_edges = 0;
        
        int m = edges.size();
        
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(obj.find(u) == obj.find(v)){
                additional_edges++;
            }
            else{
                obj.Union(u,v);
            }
        }
        
        int leaders = 0;
        
        for(int i=0;i<n;i++){
            if(obj.find(i) == i){
                leaders++;
            }
        }
        
        int req = leaders - 1;
        
        if(additional_edges >= req){
            return req;
        }
        else{
            return -1;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends