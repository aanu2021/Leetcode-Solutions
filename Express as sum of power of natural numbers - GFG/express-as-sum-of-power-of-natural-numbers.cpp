//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    
    int numOfWays(int n, int x)
    {
        vector<int>v;
        int ele = 1;
        while(pow(ele,x) <= n){
            v.push_back(pow(ele,x));
            ele++;
        }
        
        int m = v.size();
        
        // for(int &ele : v){
        //     cout<<ele<<" ";
        // }cout<<"\n";
        
        ll dp[n+1];
        memset(dp,0LL,sizeof(dp));
        
        dp[0] = 1LL;
        
        for(int i=0;i<m;i++){
            int ele = v[i];
            for(int j=n;j>=ele;j--){
                dp[j] += dp[j-ele];
                dp[j] %= M;
            }
        }
        
        return dp[n];
        
    }
};

/*

Top Down Approach

Time Complexity : O(N*M) 
Space Complexity : O(N*M)


Bottom Up Approach

dp[i][target] 

dp[i-1][target] + dp[i-1][target-ele]

1 32 

*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends