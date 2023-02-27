//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    typedef long long int ll;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<ll>prefix(n,1LL);
        vector<ll>suffix(n,1LL);
        for(ll i=1;i<n;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(ll i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        vector<ll>ans(n);
        for(ll i=0;i<n;i++){
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends