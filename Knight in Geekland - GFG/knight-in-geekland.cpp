//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &grid){
        int dx[8] = {2,2,1,1,-2,-2,-1,-1};
        int dy[8] = {1,-1,2,-2,1,-1,2,-2};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[start_x][start_y] = 1;
        queue<pair<int,int>>q;
        q.push({start_x,start_y});
        int lvl = 0;
        vector<int>dp;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            while(sz--){
                auto curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;
                sum += grid[x][y];
                for(int dir=0;dir<8;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny]==0){
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            dp.push_back(sum);
            lvl++;
        }
        n = dp.size();
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }cout<<"\n";
        for(int i=n-1;i>=0;i--){
            if(i + dp[i] < n){
                dp[i] += dp[i+dp[i]];
            }
        }
        int maxi = *max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) return i;
        }
        return 0;
    }
};

/*

x step -> y coins
(x+y) -th step all coins can be collected


* * *
* 1 *
* * *

step = 0

2

step = 1

15

step = 2

13

step = 3

14

step = 4

6


dp = 15 15 13 14 6

3 8
2 5
2 6 4 3 4 4 5 7
3 1 4 4 8 9 3 2
7 4 2 3 7 8 5 2
       
*/



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends