//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &interval){
        sort(interval.begin(),interval.end());
        vector<int>dp(n);
        int maxi = interval[n-1][2];
        dp[n-1] = interval[n-1][2];
        for(int i=n-2;i>=0;i--){
            int low = i+1,high = n-1;
            int idx = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(interval[mid][0] >= interval[i][1]){
                    idx = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            int currValue = interval[i][2];
            if(idx != -1) currValue += dp[idx];
            maxi = max(maxi,currValue);
            dp[i] = interval[i][2];
            dp[i] = max(dp[i],dp[i+1]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends