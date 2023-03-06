//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        vector<int>prefix(32,0);
        for(int i=31;i>=0;i--){
            if((n&(1<<i))) prefix[i]++;
        }
        int ans = 0;
        int cnt = 0;
        for(int i=31;i>=0;i--){
            if(prefix[i]==0){
                cnt = 0;
                continue;
            }
            else{
                cnt++;
                if(cnt == 3){
                    cnt = 0;
                }
                else{
                    ans |= (1<<i);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends