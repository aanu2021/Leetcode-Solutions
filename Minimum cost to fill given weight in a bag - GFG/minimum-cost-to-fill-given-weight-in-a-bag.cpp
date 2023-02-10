//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int>dp(W+1,1e9);
        dp[0] = 0;
        for(int i=0;i<N;i++){
            if(cost[i]==-1) continue;
            int wt = i+1;
            int currCost = cost[i];
            for(int j=wt;j<=W;j++){
                dp[j] = min(dp[j],dp[j-wt] + currCost);
            }
        }
        if(dp[W] >= 1e9) return -1;
        else return dp[W];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends