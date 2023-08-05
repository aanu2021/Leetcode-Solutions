//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n = s.length();
        int maxLen = 0;
        int startIdx = 0;
        for(int i=0;i<n;i++){
            int low = i-1, high = i+1;
            while(low >= 0 && s[low]==s[i]){
                low--;
            }
            while(high <n && s[high]==s[i]){
                high++;
            }
            while(low >= 0 && high < n && s[low] == s[high]){
                low--;
                high++;
            }
            int currLen = high - low - 1;
            if(currLen > maxLen){
                maxLen = currLen;
                startIdx = low+1;
            }
        }
        return s.substr(startIdx, maxLen);
    }
};

//{ Driver Code Starts.

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