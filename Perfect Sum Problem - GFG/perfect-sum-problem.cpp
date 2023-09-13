//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	typedef long long ll;
	const ll M = 1e9 + 7;
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<ll>dp(sum+1,0LL);
        dp[0] = 1LL;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                dp[j] += dp[j-arr[i]];
                dp[j] %= M;
            }
        }
        return dp[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends