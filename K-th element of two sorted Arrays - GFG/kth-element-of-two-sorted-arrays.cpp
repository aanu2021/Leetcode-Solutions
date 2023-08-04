//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        // cout<<n<<" "<<m<<" "<<k<<"\n";
        
        int low = 0, high = n;
        
        // int answer = INT_MAX;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            int partX = mid;
            if(mid > k){
                high = mid - 1;
                continue;
            }
            int partY = k - partX;
            if(partY > m){
                low = mid + 1;
                continue;
            }
            else{
                
                int maxLeftX  = INT_MIN;
                int maxLeftY  = INT_MIN;
                int minRightX = INT_MAX;
                int minRightY = INT_MAX;
                
                if(partX != 0) maxLeftX = arr1[partX-1];
                if(partY != 0) maxLeftY = arr2[partY-1];
                if(partX != n) minRightX = arr1[partX];
                if(partY != m) minRightY = arr2[partY];
                
                if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                    return max(maxLeftX, maxLeftY); 
                }
                else if(maxLeftX > minRightY){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        
        // cout<<"adasdas\n";
        
        low = 0, high = m;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            int partX = mid;
            
            if(partX > k){
                high = mid - 1;
                continue;
            }
            int partY = k - partX;
            if(partY > n){
                low = mid + 1;
                continue;
            }
            else{
                
                // cout<<mid<<" "<<partX<<" "<<partY<<"\n";
                
                int maxLeftX  = INT_MIN;
                int maxLeftY  = INT_MIN;
                int minRightX = INT_MAX;
                int minRightY = INT_MAX;
                
                if(partX != 0) maxLeftX = arr2[partX-1];
                if(partY != 0) maxLeftY = arr1[partY-1];
                if(partX != m) minRightX = arr2[partX];
                if(partY != n) minRightY = arr1[partY];
                
                if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                    return max(maxLeftX, maxLeftY); 
                }
                else if(maxLeftX > minRightY){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        
        
        return -1;
        
    }
};

/*

2 3 6 7  9
1 4 8 10

low = 0
high = 5
mid = 2

*/


//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends