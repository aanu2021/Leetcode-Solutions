//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        
        int n = s.length();
        
        // check whether wrong pairing alreasy available or not.
        for(int i=0;i<n/2;i++){
            if(s[i]=='?'){
                if(s[n-i-1]=='?'){
                    continue;
                }
                else{
                    s[i] = s[n-i-1];
                }
            }
            else{
                if(s[n-i-1]=='?'){
                    s[n-i-1] = s[i];
                }
                else{
                    if(s[i] != s[n-i-1]) return -1;
                }
            }
        }
        
        int idx = -1;
        
        for(int j=n/2;j<n;j++){
            if(s[j] != '?'){
                idx = j;
                break;
            }
        }
        
        if(idx==-1){
            
            for(int i=0;i<n;i++){
                s[i] = 'a';
            }
            
        }
        
        else{
            
            for(int i=n/2-1;i>=0;i--){
                if(s[i] != '?'){
                    idx = i;
                    continue;
                }
                else{
                    s[i] = s[idx];
                    continue;
                }
            }
            
              for(int i=0;i<n/2;i++){
                    if(s[i]=='?'){
                        if(s[n-i-1]=='?'){
                            continue;
                        }
                        else{
                            s[i] = s[n-i-1];
                        }
                    }
                    else{
                        if(s[n-i-1]=='?'){
                            s[n-i-1] = s[i];
                        }
                        else{
                            if(s[i] != s[n-i-1]) return -1;
                        }
                    }
              }
            
        }
        
        int sum = 0;
        for(int i=1;i<n;i++){
            sum += abs(s[i]-s[i-1]);
        }
        // cout<<s<<"\n";
        return sum;
    }
};

// a _ _ _ c _ _ c _ _ _ a
// 0 1 2 3 4 5 6 7 8 9 10 11


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends