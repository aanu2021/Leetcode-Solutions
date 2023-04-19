//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        vector<int>prefixSum(N+2,0);
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                int l = max(0,i-X);
                int r = min(N-1,i+X);
                prefixSum[l]++; prefixSum[r+1]--;
            }
        }
        for(int i=1;i<N;i++){
            prefixSum[i] += prefixSum[i-1];
        }
        for(int i=0;i<N;i++){
            if(prefixSum[i]==0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends