//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    typedef long long int ll;
    
    long long int sumXOR(int arr[], int n)
    {
    	ll totalSum = 0LL;
    	vector<int>bits(32,0);
    	for(int i=0;i<n;i++){
    	    int ele = arr[i];
    	    for(int j=20;j>=0;j--){
    	        if((ele&(1<<j))){
    	            bits[j]++;
    	        }
    	    }
    	}
    	for(int i=0;i<n;i++){
    	    int ele = arr[i];
    	    for(int j=0;j<=20;j++){
    	        if((ele&(1<<j))){
    	            totalSum += ((n-bits[j])*(1LL<<j));
    	        }
    	        else{
    	            totalSum += ((bits[j])*(1LL<<j));
    	        }
    	    }
    	}
    	return (totalSum/2);
    }
};

// 7 3 5

// 111   011   101

// 2   2   3

// 4 + 2 + 8 + 2 + 4 + 4 


//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends