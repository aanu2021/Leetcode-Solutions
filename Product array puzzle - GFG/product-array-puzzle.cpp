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
        int cntZero = 0;
        ll prod = 1LL;
        for(ll &ele : nums){
            if(ele == 0){
                cntZero++;
            }
            else{
                prod *= ele;
            }
        }
        for(int i=0;i<n;i++){
            if(cntZero > 1){
                nums[i] = 0LL;
            }
            else if(cntZero == 1){
                if(nums[i] == 0LL){
                    nums[i] = prod;
                }
                else{
                    nums[i] = 0LL;
                }
            }
            else{
                nums[i] = prod/nums[i];
            }
        }
        return nums;
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