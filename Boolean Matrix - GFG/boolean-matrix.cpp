//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int isRow = 0, isCol = 0;
        if(grid[0][0]){
            isRow = 1;
            isCol = 1;
        }
        for(int i=1;i<n;i++){
            if(grid[0][i]==1){
                isRow = 1;
            }
        }
        for(int i=1;i<m;i++){
            if(grid[i][0]==1){
                isCol = 1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    grid[0][j] = 1;
                    grid[i][0] = 1;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(grid[i][0]==1){
                for(int j=0;j<n;j++){
                    grid[i][j] = 1;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(grid[0][j]==1){
                for(int i=0;i<m;i++){
                    grid[i][j] = 1;
                }
            }
        }
        if(isRow){
            for(int i=0;i<n;i++){
                grid[0][i] = 1;
            }
        }
        if(isCol){
            for(int i=0;i<m;i++){
                grid[i][0] = 1;
            }
        }
    }
};

/*

isRow = 1
isCol = 1

1 1 1
1 1 1
1 1 1
1 1 0

*/


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends