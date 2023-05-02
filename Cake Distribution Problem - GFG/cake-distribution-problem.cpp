//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    typedef long long ll;
    
    bool canPlace(vector<int>&arr,int N,int K,ll target){
        int placed = 0;
        ll currSum = 0LL;
        for(int i=0;i<N;i++){
            currSum += (ll)arr[i];
            if(currSum >= target){
                placed++;
                currSum = 0LL;
            }
        }
        return placed >= K;
    }
    
    int maxSweetness(vector<int>& arr, int N, int K) {
       
       ll sum = accumulate(arr.begin(),arr.end(),0LL);
       ll low = 0, high = sum;
       K++;
       ll ans = -1LL;
       while(low <= high){
           ll mid = (low + high)/2;
           if(canPlace(arr,N,K,mid)){
               ans = mid;
               low = mid + 1;
           }
           else{
               high = mid - 1;
           }
       }
       return (int)ans;
       
    }
};


// Maximize the Minimum -> Binary Search









//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends