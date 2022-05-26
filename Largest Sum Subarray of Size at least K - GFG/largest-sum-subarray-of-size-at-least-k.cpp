// { Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


typedef long long ll;

long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    
    vector<ll>maxsum(n+1,0LL);
    
    ll currsum=0LL;
    
    for(ll i=0;i<n;i++){
        
        currsum+=arr[i];
        
        maxsum[i]=currsum;
        
        if(currsum<0){
            currsum=0LL;
        }
        
    }
    
    
    ll maxval=-1LL;
    
    currsum=0LL;
    
    for(ll i=0;i<k;i++){
        currsum+=arr[i];
    }
    
    maxval=currsum;
    
    for(ll i=k;i<n;i++){
        
        currsum+=arr[i];
        currsum-=arr[i-k];
        
        maxval=max(maxval,currsum);
        maxval=max(maxval,currsum+maxsum[i-k]);
        
    }
    
    return maxval;
    
}