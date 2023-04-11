//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        int mx = max({a,b,c});
        if(mx <= 2*(a+b+c-mx+1)){
            return a+b+c;
        }
        else{
            return -1;
        }
    }
};


// a = 6
// b = 3
// c = 3

// bbaaccaabacaa


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends