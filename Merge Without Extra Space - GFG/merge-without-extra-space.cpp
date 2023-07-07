//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            
            int i = 0,j = 0,k = n-1;
            
            while(i <= k && j < m){
                if(arr1[i] <= arr2[j]){
                    i++;
                }
                else{
                    swap(arr2[j++],arr1[k--]);
                }
            }
            
            sort(arr1,arr1 + n);
            sort(arr2,arr2 + m);
            
        } 
};

/*

This is more like a merge sort step.

We are given with two sorted arrays.

We have to merge them.

[a1, a2, a3, a4]   [b1, b2, b3, b4, b5]
 
*/



//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends