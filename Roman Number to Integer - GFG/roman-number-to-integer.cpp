//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    int values(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
  
    int romanToDecimal(string &s) {
        int n = s.length();
        int vals = 0;
        int prev_value = 0;
        for(int i=n-1;i>=0;i--){
            if(values(s[i]) < prev_value){
                vals -= values(s[i]);
            }
            else{
                vals += values(s[i]);
            }
            prev_value = values(s[i]);
        }
        return vals;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends