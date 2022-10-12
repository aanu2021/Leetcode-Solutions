// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    typedef long long ll;
    
    ll mergefunc(vector<ll>&arr,ll low,ll mid,ll high){
        
        ll ans=0LL;
        
        vector<ll>temp(high-low+1);
        
        ll k=0LL;
        
        ll i=low,j=mid+1;
        
        while(i<=mid && j<=high){
            
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                ans += (mid+1-i);
                temp[k++] = arr[j++];
            }
            
        }
        
        while(i<=mid){
            
            temp[k++]=arr[i++];
            
        }
        
        while(j<=high){
            
            temp[k++]=arr[j++];
            
        }
        
        k=0LL;
        
        for(ll idx=low;idx<=high;idx++){
            
            arr[idx]=temp[k++];
            
        }
        
        return ans;
        
    }
    
    ll mergesort(vector<ll>&arr,ll low,ll high){
        
        ll ans=0LL;
        
        if(low<high){
            
            ll mid=(low+high)/2;
            
            ans+=mergesort(arr,low,mid);
            
            ans+=mergesort(arr,mid+1,high);
            
            ans+=mergefunc(arr,low,mid,high);
            
        }
        
        return ans;
        
    }
    
    long long int inversionCount(long long a[], long long n)
    {
        
        vector<ll>arr;
        
        for(ll i=0;i<n;i++){
            arr.push_back(a[i]);
        }
        
        return mergesort(arr,0,n-1);
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends