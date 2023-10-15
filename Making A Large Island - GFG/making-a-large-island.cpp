//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    vector<int>Parent;
    vector<int>Size;
    
    int find(int x){
        if(Parent[x] == x) return x;
        return Parent[x] = find(Parent[x]);
    }
    void Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Size[lx] > Size[ly]){
                Size[lx] += Size[ly];
                Parent[ly] = lx;
            }
            else{
                Size[ly] += Size[lx];
                Parent[lx] = ly;
            }
        }
    }
    int getSize(int x){
        int lx = find(x);
        return Size[lx];
    }
    int getCell(int i,int j,int n){
        return (i*n) + j;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int L = n*n;
        Parent.clear();
        Size.clear();
        Parent.resize(L);
        Size.resize(L,0);
        for(int i=0;i<L;i++){
            Parent[i] = i;
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    Size[getCell(i,j,n)]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                     for(int d=0;d<4;d++){
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj]){
                            Union(getCell(i,j,n),getCell(ni,nj,n));
                        }
                    }
                }
            }
        }
        // unordered_set<int>vis;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]){
        //             vis.insert(find(getCell(i,j,n)));
        //         }
        //     }
        // }
        // for(auto &ele : vis){
        //     cout<<ele<<" "<<getSize(find(ele))<<"\n";
        // }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>S;
                    for(int d=0;d<4;d++){
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj]){
                            S.insert(find(find(getCell(ni,nj,n))));
                        }
                    }
                    int currArea = 1;
                    for(auto &ele : S){
                        int siz = getSize(ele);
                        //  if(i==3 && j==1){
                        //   cout<<ele<<" "<<siz<<"\n";
                        //  }
                        currArea += siz;
                    }
                    maxArea = max(maxArea, currArea);
                }
                else{
                    maxArea = max(maxArea, getSize(find(getCell(i,j,n))));
                }
            }
        }
        return maxArea;
    }
};


/*


1 0 0 1
0 0 0 0
0 0 0 0
1 0 0 1


*/




//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends