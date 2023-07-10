//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int grid[MAX][MAX],int m,int n,int k)
    {
 		
 		int row_start = 0, row_end = m-1, col_start = 0, col_end = n-1;
 		
 		while(k > 0 && row_start <= row_end && col_start <= col_end){
 		    
 		    for(int col=col_start;col<=col_end && k>0;col++){
 		        k--;
 		        if(k==0) return grid[row_start][col];
 		    }
 		    
 		    row_start++;
 		    
 		    for(int row=row_start;row<=row_end && k>0;row++){
 		        k--;
 		        if(k==0) return grid[row][col_end];
 		    }
 		    
 		    col_end--;
 		    
 		    for(int col=col_end;col>=col_start && k>0;col--){
 		        k--;
 		        if(k==0) return grid[row_end][col];
 		    }
 		    
 		    row_end--;
 		    
 		    for(int row=row_end;row>=row_start && k>0;row--){
 		        k--;
 		        if(k==0) return grid[row][col_start];
 		    }
 		    
 		    col_start++;
 		    
 		}
 		
 		return -1;
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends