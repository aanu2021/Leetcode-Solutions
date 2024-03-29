//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
    
        vector<int>minL(n);
        vector<int>maxR(n);
        
        minL[0] = arr[0];
        maxR[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            minL[i] = min(minL[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxR[i] = max(maxR[i+1],arr[i]);
        }
        
        int i=0,j=0;
        int maxDiff = 0;
        
        while(i<n && j<n){
            if(minL[i] <= maxR[j]){
                maxDiff = max(maxDiff,j-i);
                j++;
            }
            else{
                i++;
            }
        }
    
    
        return maxDiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends