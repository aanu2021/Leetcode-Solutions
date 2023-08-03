//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited,string path,int n,vector<string>&answer){
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        if(grid[i][j]==0) return;
        if(visited[i][j]) return;
        if(i==n-1 && j==n-1){
            answer.push_back(path);
            return;
        }
        visited[i][j] = true;
        dfs(grid,i+1,j,visited,path+"D",n,answer);
        dfs(grid,i-1,j,visited,path+"U",n,answer);
        dfs(grid,i,j-1,visited,path+"L",n,answer);
        dfs(grid,i,j+1,visited,path+"R",n,answer);
        visited[i][j] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string>answer;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        dfs(grid,0,0,visited,"",n,answer);
        return answer;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends