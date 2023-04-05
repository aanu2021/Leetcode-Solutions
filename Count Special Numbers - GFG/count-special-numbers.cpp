//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        
       int maxi = *max_element(arr.begin(),arr.end());
       vector<int>freq(maxi+1,0);
       vector<int>vis(maxi+1,0);
       
       for(int &ele : arr){
           freq[ele]++;
       }
       
       for(int i=1;i<=maxi;i++){
           if(freq[i] > 1){
               vis[i] = 1;
           }
       }
       
       for(int i=1;i<=maxi;i++){
           if(freq[i]==0) continue;
           for(int j=2*i;j<=maxi;j+=i){
               vis[j] = 1;
           }
       }
       
       int ans = 0;
       for(int i=1;i<=maxi;i++){
           if(vis[i]){
               ans += freq[i];
           }
       }
       return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends