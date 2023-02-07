//{ Driver Code Starts
// Initial Template for C++

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
  
    int getCell(int x,int y,int m,int n){
        return (x*n) + y;
    }
  
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &operators) {
        DSU obj(m*n + 5);
        vector<int>answer;
        int ans = 0;
        vector<vector<int>>grid(m,vector<int>(n,0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i=0;i<operators.size();i++){
            int x = operators[i][0];
            int y = operators[i][1];
            if(grid[x][y]){
                answer.push_back(ans);
            }
            else{
                grid[x][y] = 1;
                ans++;
                int node = getCell(x,y,m,n);
                for(int dir = 0;dir < 4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]){
                        int nbr = getCell(nx,ny,m,n);
                        if(obj.find(node)==obj.find(nbr)) continue;
                        obj.Union(node,nbr);
                        ans--;
                    }
                }
                answer.push_back(ans);
            }
        }
        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends