//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        sort(arr,arr+n);
        int minOcc = n+1;
        for(int i=0;i<n;i++){
            int j = i;
            int currOcc = 0;
            while(j<n && arr[j]==arr[i]){
                currOcc++;
                j++;
            }
            minOcc = min(minOcc,currOcc);
            i = j;
            i--;
        }
        for(int i=n-1;i>=0;i--){
            int j = i;
            int currOcc = 0;
            while(j >= 0 && arr[j] == arr[i]){
                currOcc++;
                j--;
            }
            if(currOcc == minOcc) return arr[i];
            i = j;
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends