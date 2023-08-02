//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    typedef long long int ll;
    
    ll merge(long long arr[],long long temp[],int low,int mid,int high){
        
        ll cnt = 0LL;
        
        int i = low;
        int j = mid+1;
        int idx = low;
        
        for(int i=low;i<=mid;i++){
            while(j<=high && arr[i] > arr[j]){
                j++;
            }
            cnt += (ll)(j-mid-1);
        }
        
        i = low, j = mid + 1;
        idx = low;
        
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                temp[idx++] = arr[i++];
            }
            else{
                temp[idx++] = arr[j++];
            }
        }
        
        while(i<=mid){
            temp[idx++] = arr[i++];
        }
        while(j<=high){
            temp[idx++] = arr[j++];
        }
        
        for(int index=low;index<=high;index++){
            arr[index] = temp[index];
        }
        
        return cnt;
        
    }
    
    ll mergesort(long long arr[],long long temp[],int low,int high){
        ll cnt = 0LL;
        if(low < high){
            int mid = (low + high)/2;
            cnt += mergesort(arr,temp,low,mid);
            cnt += mergesort(arr,temp,mid+1,high);
            cnt += merge(arr,temp,low,mid,high);
        }
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        ll answer = mergesort(arr,temp,0,N-1);
        return answer;
    }

};

//{ Driver Code Starts.

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