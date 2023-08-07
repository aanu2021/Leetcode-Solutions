//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    
    bool isSafe(int grid[N][N],int row,int col,int num){
        // column check
        for(int i=0;i<N;i++){
            if(grid[row][i] == num){
                return false;
            }
        }
        // row check
        for(int i=0;i<N;i++){
            if(grid[i][col] == num){
                return false;
            }
        }
        // submatrices check
        int smi = (row/3)*3;
        int smj = (col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i+smi][j+smj] == num){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(int grid[N][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int num=1;num<=9;num++){
                        if(isSafe(grid,i,j,num)){
                            grid[i][j] = num;
                            if(solve(grid)){
                                return true;
                            }
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends