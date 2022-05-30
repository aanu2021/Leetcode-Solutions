// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    typedef long long ll;
    
    int circularSubarraySum(int arr[], int n){
        
       ll maxsum=LONG_MIN;
       ll minsum=LONG_MAX;
       
       ll arraysum=0LL;
       
       ll tempmax=0LL;
       ll tempmin=0LL;
       
       for(ll i=0;i<n;i++){
           
           arraysum+=(ll)arr[i];
           
           tempmax+=(ll)arr[i];
           tempmin+=(ll)arr[i];
           
           maxsum=max(maxsum,tempmax);
           minsum=min(minsum,tempmin);
           
           if(tempmax<0){
               tempmax=0LL;
           }
           
           if(tempmin>0){
               tempmin=0LL;
           }
           
       }
       
       
       if(minsum==arraysum){
           return maxsum;
       }
       
       else{
           return max(maxsum,arraysum-minsum);
       }
        
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends