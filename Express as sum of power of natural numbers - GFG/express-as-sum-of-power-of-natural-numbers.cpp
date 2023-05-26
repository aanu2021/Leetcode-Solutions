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
    
    ll dp[1003][1003];
    
    ll func(vector<int>&nums,int i,int target,int n){
        
        if(target < 0) return 0LL;
    
        if(i==n){
            if(target==0) return 1LL;
            else return 0LL;
        }
        
        if(dp[i][target] != -1LL) return dp[i][target];
        
        ll ans = func(nums,i+1,target,n);
        ans += func(nums,i+1,target-nums[i],n);
        ans %= M;
        
        return dp[i][target] = ans;
    
    }
    
    int numOfWays(int n, int x)
    {
        vector<int>v;
        int ele = 1;
        while(ele <= n){
            v.push_back(pow(ele,x));
            ele++;
        }
        
        int m = v.size();
        memset(dp,-1LL,sizeof(dp));
        
        ll ans = func(v,0,n,m);
        return ans;
        
    }
};





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