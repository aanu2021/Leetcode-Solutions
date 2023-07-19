//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0,j=0;
    	int curr = 0, ans = 0;
    	
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        curr++;
    	        i++;
    	    } 
    	    else{
    	        curr--;
    	        j++;
    	    }
    	    ans = max(ans,curr);
    	}
    	return ans;
    	
    }
};


/*
                              i
900 940  950  1100 1500 1800
910 1120 1130 1200 1900 2000
                    j

curr = 2
ans = 3

*/


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends