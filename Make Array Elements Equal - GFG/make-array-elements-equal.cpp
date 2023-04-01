//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    typedef long long int ll;
  
    long long int minOperations(int N) {
        ll M = (ll)N/2;
        if(N%2){
            return (M*(M+1));
        }
        else{
            return (M*M);
        }
    }
};

/*

N -> even

1 3 5 7 9 11

req = 6

M = (N/2)

5 + 3 + 1 

1 + 3 + 5 + ... upto M times

M/2 * (2 + (M-1)*2)
M/2 * (2*M)
M^2

N -> odd

1 3 5 7 9 11 13 15 17 19 21

20 + 16 + 12 + 8 + 4

4*(1 + 2 + 3 + .... + N/2 times)

4*5*6/2 = 2*5*6 = 60

*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends