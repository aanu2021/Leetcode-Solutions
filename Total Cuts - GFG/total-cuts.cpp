//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int>prefixMax(N);
        vector<int>suffixMin(N);
        
        prefixMax[0] = A[0];
        suffixMin[N-1] = A[N-1];
        
        for(int i=1;i<N;i++){
            prefixMax[i] = max(prefixMax[i-1],A[i]);
        }
        for(int i=N-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],A[i]);
        }
        
        int cnt = 0;
        
        for(int i=0;i<N-1;i++){
            if(prefixMax[i] + suffixMin[i+1] >= K){
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends