//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    typedef long long ll;
    const ll M = 1e9 + 7;
  
    int nthFibonacci(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        ll a = 1LL, b = 1LL;
        for(int i=3;i<=n;i++){
            ll c = (a+b)%M;
            a = b;
            b = c;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends