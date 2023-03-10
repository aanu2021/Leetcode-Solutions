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
    	ll min1 = 1e18;
    	ll min2 = 1e18;
    	
    	for(int i=0;i<n;i++){
    	    if(arr[i] <= min1){
    	        min2 = min1;
    	        min1 = arr[i];
    	    }
    	    else if(arr[i] <= min2){
    	        min2 = arr[i];
    	    }
    	}
    	
    	ll max1 = -1e18;
    	ll max2 = -1e18;
    	ll max3 = -1e18;
    	
    	for(int i=0;i<n;i++){
    	    if(arr[i] >= max1){
    	        max3 = max2;
    	        max2 = max1;
    	        max1 = arr[i];
    	    }
    	    else if(arr[i] >= max2){
    	        max3 = max2;
    	        max2 = arr[i];
    	    }
    	    else if(arr[i] >= max3){
    	        max3 = arr[i];
    	    }
    	}
    	
    	ll maxProd = (max1*max2*max3);
    	maxProd = max(maxProd,max1*min1*min2);
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