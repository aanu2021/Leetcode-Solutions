//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    typedef long long ll;

    vector<long long> smallerSum(int n,vector<int> &arr){
        
        vector<int>vec;
        for(int i=0;i<n;i++){
            vec.push_back(arr[i]);
        }
        
        sort(vec.begin(),vec.end());
        vector<ll>prefix(n,0LL);
        prefix[0] = (ll)vec[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + (ll)vec[i];
        }
        
        vector<ll>answer(n,0LL);
        
        for(int i=0;i<n;i++){
            int ele = arr[i];
            int j = lower_bound(vec.begin(),vec.end(),ele) - vec.begin();
            if(j-1 >= 0){
                answer[i] = prefix[j-1];
            }
        }
        return answer;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends