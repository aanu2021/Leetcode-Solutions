//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,0));
        for(int i=1;i<N-1;i++){
            dp[i][i+1] = arr[i-1]*arr[i]*arr[i+1];
        }
        for(int L=3;L<N;L++){
            for(int i=1;i<=N-L;i++){
                int j = i+L-1;
                dp[i][j] = INT_MAX;
                for(int k=i;k<=j-1;k++){
                    dp[i][j] = min(dp[i][j], (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends