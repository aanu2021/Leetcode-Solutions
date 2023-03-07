//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isNumeric(char ch){
        if(ch >= '0' && ch <= '9') return true;
        else return false;
    }
  
    int checkCompressed(string S, string T) {
        int n = S.length();
        int m = T.length();
        int i = 0 , j = 0;
        for(i=0;i<m;i++){
            if(j == n) return 0;
            if(T[i] >= 'A' && T[i] <= 'Z'){
                if(S[j] != T[i]) return 0;
                else{
                    j++;
                }
            }
            else{
                int idx = i;
                int value = 0;
                while(idx < m && isNumeric(T[idx]) && value < n){
                    value = (value*10) + (T[idx]-'0');
                    idx++;
                }
                int rest_char = (n-j);
                // cout<<value<<" "<<rest_char<<"\n";
                // cout<<i<<" "<<j<<"\n";
                if(rest_char < value) return 0;
                else{
                    i = idx;
                    j += value;
                    // cout<<i<<" "<<j<<"\n";
                    i--;
                }
            }
        }
        return (i==m && j==n);
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