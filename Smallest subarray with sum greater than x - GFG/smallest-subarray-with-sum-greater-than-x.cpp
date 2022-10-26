//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        
        int sum = 0;
        
        int l=0,r=0;
        
        int minLen = n+1;
        
        while(l<n && r<n){
            
            sum+=arr[r];
            
            while(l<=r && sum>x){
                
                minLen = min(minLen,r-l+1);
                
                sum-=arr[l];
                
                l++;
                
            }
            
            r++;
            
        }
        
        return minLen==n+1 ? 0 : minLen;
         
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends