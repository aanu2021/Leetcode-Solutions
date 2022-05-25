// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        
        int n=s.length();
        
        int maxLen=0,startidx=-1;
        
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
            }else{
                dp[i][i+1]=false;
            }
            
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }
                
            }
            
        }
        
        
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                if(dp[i][j]==true){
                    
                    int currlen=(j-i+1);
                    
                    if(currlen>maxLen){
                        maxLen=currlen;
                        startidx=i;
                    }
                    
                }
                
            }
            
        }
        
        return s.substr(startidx,maxLen);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends