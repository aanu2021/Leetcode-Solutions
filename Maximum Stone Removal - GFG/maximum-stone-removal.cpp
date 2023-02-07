//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DSU{
  
  public:
  
  vector<int>Parent;
  vector<int>Size;
  
  DSU(int n){
      Parent.resize(n);
      Size.resize(n);
      for(int i=0;i<n;i++){
          Parent[i] = i;
          Size[i] = 1;
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
          if(Size[lx] > Size[ly]){
              Parent[ly] = lx;
              Size[lx] += Size[ly];
          }
          else{
              Parent[lx] = ly;
              Size[ly] += Size[lx];
          }
      }
  }
  
  int getSize(int x){
      int lx = find(x);
      return Size[lx];
  }
    
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        DSU obj(n);
        unordered_map<int,vector<int>>row,col;
        for(int i=0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1];
            row[r].push_back(i);
            col[c].push_back(i);
        }
        for(auto &itr:row){
            int leader = itr.second[0];
            for(auto &ele:itr.second){
                obj.Union(leader,ele);
            }
        }
        for(auto &itr:col){
            int leader = itr.second[0];
            for(auto &ele:itr.second){
                obj.Union(leader,ele);
            }
        }
        int maxSize = 0;
        for(int i=0;i<n;i++){
            if(obj.find(i) == i){
                maxSize += (obj.getSize(i) - 1);
            }
        }
        return maxSize;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends