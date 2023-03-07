//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &grid, int n) {
        int x = grid[0][0];
        int y = grid[0][1];
        int z = grid[0][2];
        for(int i=1;i<n;i++){
            int nx = grid[i][0] + min(y,z);
            int ny = grid[i][1] + min(x,z);
            int nz = grid[i][2] + min(x,y);
            x = nx;
            y = ny;
            z = nz;
        }
        return min({x,y,z});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends