//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = (str[i]==str[i+1]);
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i+L-1;
                if(str[i]==str[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        vector<int>cuts(n+1,1e9);
        cuts[n] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    cuts[i] = min(cuts[i], 1 + cuts[j+1]);
                }
            }
        }
        return cuts[0] - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends