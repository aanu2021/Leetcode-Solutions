//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    typedef long long ll;
  
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	ll maxProd = -1e18;
    	maxProd = arr[0]*arr[1]*arr[n-1];
    	maxProd = max(maxProd,arr[n-1]*arr[n-2]*arr[n-3]);
    	return maxProd;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends