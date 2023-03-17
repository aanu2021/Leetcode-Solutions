//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

typedef long long int ll;

long long int no_of_subarrays(int n, vector<int> &arr) {
    
    ll ans = 0LL;
    
    for(int i=0;i<n;i++){
        if(arr[i]) continue;
        int j = i;
        ll cnt = 0LL;
        while(j<n && arr[j]==0){
            cnt++;
            j++;
        }
        ans += (cnt*(cnt+1))/2LL;
        i = j;
        i--;
    }
    return ans;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends