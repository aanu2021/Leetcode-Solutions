//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isAlphabet(char ch){
        if(ch >= 'A' && ch <= 'Z') return true;
        else return false;
    }
    
    bool isNumeric(char ch){
        if(ch >= '0' && ch <= '9') return true;
        else return false;
    }
  
    int checkCompressed(string S, string T) {
        int m = S.length();
        int n = T.length();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(isAlphabet(T[i])){
                if(T[i] != S[j]) return 0;
                i++;
                j++;
            }
            else{
                int value = 0;
                int idx = i;
                while(idx < n && isNumeric(T[idx]) && value <= m){
                    value = (value*10) + (T[idx]-'0');
                    idx++;
                }
                int rest_of_char = (m-j);
                if(rest_of_char < value) return 0;
                i  = idx;
                j += value;
            }
        }
        return (i==n && j==m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends