//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
          if(Size[lx]<Size[ly]){
              Parent[lx] = ly;
              Size[ly] += Size[lx];
          }
          else{
              Parent[ly] = lx;
              Size[lx] += Size[ly];
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
  
    int getCell(int x,int y,int n){
        return (x*n) + y;
    }
    
    bool isSafeCell(int x,int y,int n){
        if(x>=0 && x<n && y>=0 && y<n) return true;
        else return false;
    }
  
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        DSU obj1(n*n + 10);
        DSU obj2(n*n + 10);
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int node = getCell(i,j,n);
                    for(int dir=0;dir<4;dir++){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<"\n";
                        if(isSafeCell(ni,nj,n) && grid[ni][nj]){
                                int nbr = getCell(ni,nj,n);
                             // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<"\n";
                             // cout<<node<<" "<<nbr<<"\n";
                                obj1.Union(node,nbr);
                        }
                    }
                }
            }
        }
        
        // for(int i=0;i<n*n;i++){
        //     cout<<obj1.find(i)<<" "<<obj1.getSize(i)<<"\n";
        // }
        
        int maxComp = 0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    set<int>S;
                    for(int dir=0;dir<4;dir++){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if(isSafeCell(ni,nj,n) && grid[ni][nj]){
                            int nbr = getCell(ni,nj,n);
                            //cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<"\n";
                            S.insert(obj1.find(nbr));
                           // cout<<obj1.find(nbr)<<"\n";
                        }
                    }
                    int currComp = 1;
                    for(auto &ele:S){
                        // cout<<ele<<"\n";
                        currComp += obj1.getSize(ele);
                    }
                    //cout<<i<<" "<<j<<" "<<currComp<<"\n";
                    maxComp = max(maxComp,currComp);
                }
                else{
                    int curr = getCell(i,j,n);
                    int currComp = obj1.getSize(curr);
                    maxComp = max(maxComp,currComp);
                }
            }
        }
        
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==0){
        //             int node = getCell(i,j,n);
        //             for(int dir=0;dir<4;dir++){
        //                 int ni = i + dx[dir];
        //                 int nj = j + dy[dir];
        //                 if(isSafeCell(ni,nj,n) && grid[ni][nj]==0){
        //                     int nbr = getCell(ni,nj,n);
        //                     obj2.Union(node,nbr);
        //                 }
        //             }
        //         }
        //     }
        // }
        
        
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j] == 1){
        //             set<int>S;
        //             for(int dir=0;dir<4;dir++){
        //                 int ni = i + dx[dir];
        //                 int nj = j + dy[dir];
        //                 if(isSafeCell(ni,nj,n) && grid[ni][nj]==0){
        //                     int nbr = getCell(ni,nj,n);
        //                     S.insert(obj2.find(nbr));
        //                 }
        //             }
        //             int currComp = 1;
        //             for(auto &ele:S){
        //                 currComp += obj2.getSize(ele);
        //             }
        //             maxComp = max(maxComp,currComp);
        //         }
        //         else{
        //             int curr = getCell(i,j,n);
        //             int currComp = obj2.getSize(curr);
        //             maxComp = max(maxComp,currComp);
        //         }
        //     }
        // }
        
        return maxComp;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends