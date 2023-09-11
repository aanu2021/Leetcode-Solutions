//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    typedef long long ll;
  
    int isPerfectNumber(long long N) {
        if(N==1) return 0;
        ll totalSum = 1LL;
        for(ll i=2;i*i<=N;i++){
            if(N%i) continue;
            totalSum += i;
            if(i != (N/i)){
                totalSum += (N/i);
            }
        }
        return totalSum==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends