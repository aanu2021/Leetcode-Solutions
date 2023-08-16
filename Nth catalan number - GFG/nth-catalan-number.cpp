//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int findCatalan(int n) 
    {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<ll>dp(n+1,0LL);
        dp[0] = 1LL;
        dp[1] = 1LL;
        dp[2] = 2LL;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i] += (dp[j]*dp[i-j-1]);
                dp[i] %= M;
            }
        }
        return dp[n];
    }
};

// ()

// ()()  (())

// ()()()  (()())  (())()  ()(())  ((()))


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends