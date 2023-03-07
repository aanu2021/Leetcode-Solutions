//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    typedef long long ll;

    vector<int> optimalArray(int n,vector<int> &a){
        
        ll preSum = 0LL;
        vector<ll>prefixSum(n,0LL);
        vector<ll>prefixOps(n,0LL);
        
        for(int i=0;i<n;i++){
            preSum += (ll)a[i];
            prefixOps[i] = (ll)((ll)(i+1)*(ll)a[i]) - preSum;
            prefixSum[i] = preSum;
        }
        
        vector<int>answer(n,0);
        
        for(int i=0;i<n;i++){
            int med = (i/2);
            ll pre_req = prefixOps[med];
            ll suf_req = prefixSum[i] - prefixSum[med] - (ll)((ll)(i-med)*(ll)a[med]);
            answer[i] = pre_req + suf_req;
        }
        
        return answer;
        
    }
};

/*

1 6 9 12

inc_ops = ((i+1)*a[i]) - preSum
dec_ops = sufSum - ((n-i-1)*a[i])
tot_ops = inc_ops + dec_ops
calculate this total_ops value for every index 

*/


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends