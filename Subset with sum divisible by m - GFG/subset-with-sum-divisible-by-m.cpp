//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m){
		   
		     int n = nums.size();
		     
		     vector<vector<bool>>dp(n,vector<bool>(m,false));
		     
		     dp[0][nums[0]%m] = true;
		     
		     for(int i=1;i<n;i++){
		         
		         dp[i][nums[i]%m] = true;
		         
		         for(int j=0;j<m;j++){
		             
		             dp[i][j] = dp[i][j] || dp[i-1][j];
		             
		             int nxt = (j+nums[i])%m;
		             
		             dp[i][nxt] = dp[i][nxt] || dp[i-1][j];
		             
		         }
		         
		     }
		     
		     return dp[n-1][0];
		   
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends