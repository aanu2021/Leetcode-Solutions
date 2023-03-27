//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        
        // index , currsum , grps
        
        vector<vector<vector<int>>>dp(N+2,vector<vector<int>>(N+2,vector<int>(K+2,0)));
        vector<vector<vector<int>>>pref(N+2,vector<vector<int>>(N+2,vector<int>(K+2,0)));
        
        for(int i=1;i<=N;i++){
            dp[i][i][1] = 1;
        }
        
        
        for(int i=1;i<=N;i++){
            pref[1][i][1] += pref[1][i-1][1];
            pref[1][i][1] += dp[1][i][1];
        }
        
        // for(int i=1;i<=N;i++){
        //     cout<<pref[1][i][1]<<" ";
        // }cout<<"\n";
        
        for(int i=2;i<=N;i++){
            
            // for(int j=1;j<i;j++){
            //     for(int p=1;p<=j;p++){
            //         for(int grp=2;grp<=K;grp++){
            //             dp[i][j][grp] += dp[i-j][p][grp-1];
            //         }
            //     }
            // }
            
            for(int j=1;j<i;j++){
                for(int grp=2;grp<=K;grp++){
                    dp[i][j][grp] += pref[i-j][j][grp-1];
                }
            }
            
            for(int j=1;j<=N;j++){
                for(int grp=1;grp<=K;grp++){
                    pref[i][j][grp] += pref[i][j-1][grp];
                    pref[i][j][grp] += dp[i][j][grp];
                }
            }
            
        }
        
        // for(int i=1;i<=N;i++){
        //     cout<<dp[N][i][K]<<" ";
        // }cout<<"\n";
        
        int ans = 0;
        for(int i=1;i<=N;i++){
            ans += dp[N][i][K];
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends