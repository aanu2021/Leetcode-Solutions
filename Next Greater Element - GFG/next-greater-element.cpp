//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    
    typedef long long ll;
    
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<ll>ans(n,-1);
        
        stack<int>S;
        
        for(int i=0;i<n;i++){
            
            while(!S.empty() && arr[S.top()] < arr[i]){
                
                ans[S.top()] = arr[i];
                S.pop();
                
            }
            
            S.push(i);
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends