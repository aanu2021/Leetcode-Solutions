// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    
		    int n=s.length();
		    
		    s="*"+s;
		    
		    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		    
		    int maxLen=0;
		    
		    for(int i=1;i<=n;i++){
		        
		        for(int j=1;j<=n;j++){
		            
		            if(s[i]==s[j] && i!=j){
		                dp[i][j]=1+dp[i-1][j-1];
		            }else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		            
		            maxLen=max(maxLen,dp[i][j]);
		            
		        }
		        
		    }
		    
		    return maxLen;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends