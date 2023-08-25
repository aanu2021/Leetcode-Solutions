//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int maxLen = -1;
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<int,int>freq;
        int count = 0;
        while(r < n){
            if(freq[s[r]] == 0) count++;
            freq[s[r]]++;
            while(l<=r && count > k){
                freq[s[l]]--;
                if(freq[s[l]]==0) count--;
                l++;
            }
            if(count == k){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends