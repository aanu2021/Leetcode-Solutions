//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
  
    typedef long long ll;
  
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        ll prod = 1LL;
        int cnt = 0;
        int l = 0,r = 0;
        while(r<n){
            prod *= (ll)a[r];
            while(l <= r && prod >= k){
                prod /= (ll)a[l];
                l++;
            }
            cnt += max(r-l+1,0);
            r++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends