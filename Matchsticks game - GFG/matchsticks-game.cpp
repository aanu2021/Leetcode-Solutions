//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int matchGame(long long N) {
        
        if(N%5==0) return -1;
        else return N%5;
        
    }
};

/*

N % 5 == 0

A = 1   B = 4
A = 2   B = 3
A = 3   B = 2
A = 4   B = 1

A loose in all possible situations.....


N % 5 == 1

A = 1  (N-1)%5 == 0

B loose in all possible situations.......




*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends