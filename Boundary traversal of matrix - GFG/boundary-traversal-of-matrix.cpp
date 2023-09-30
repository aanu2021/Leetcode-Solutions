//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:

    vector<int> boundaryTraversal(vector<vector<int>>grid, int m, int n) 
    {
        vector<int>answer;
        int row_start = 0, row_end = m-1;
        int col_start = 0, col_end = n-1;
        while(row_start<=row_end && col_start<=col_end){
            for(int col=col_start;col<=col_end;col++){
                answer.push_back(grid[row_start][col]);
            }
            row_start++;
            for(int row=row_start;row<=row_end;row++){
                answer.push_back(grid[row][col_end]);
            }
            col_end--;
            for(int col=col_end;col>=col_start;col--){
                answer.push_back(grid[row_end][col]);
            }
            row_end--;
            for(int row=row_end;row>=row_start;row--){
                answer.push_back(grid[row][col_start]);
            }
            col_start++;
            break;
        }
        int size = 2*(m+n)-4;
        if(m==1) size = n;
        if(n==1) size = m;
        while(answer.size() > size){
            answer.pop_back();
        }
        return answer;
    }
};


// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends