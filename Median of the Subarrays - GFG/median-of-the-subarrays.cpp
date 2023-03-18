//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    typedef long long ll;
    
    vector<int>tree;

    void BuildSeg(int idx,int low,int high){
        if(low > high) return;
        if(low==high){
            tree[idx] = 0;
            return;
        }
        else{
            int mid = (low + high)/2;
            BuildSeg(2*idx+1,low,mid);
            BuildSeg(2*idx+2,mid+1,high);
            tree[idx] = (tree[2*idx+1] + tree[2*idx+2]);
        }
    }
    
    void Update(int idx,int low,int high,int pos){
        if(low > high) return;
        if(low==high){
            tree[idx]++;
            return;
        }
        else{
            int mid = (low + high)/2;
            if(pos<=mid){
                Update(2*idx+1,low,mid,pos);
            }
            else{
                Update(2*idx+2,mid+1,high,pos);
            }
            tree[idx] = (tree[2*idx+1] + tree[2*idx+2]);
        }
    }
    
    int query(int idx,int low,int high,int l,int r){
        if(low > high || low > r || high < l) return 0;
        if(low==high) return tree[idx];
        else if(low>=l && high<=r) return tree[idx];
        else{
            int mid = (low + high)/2;
            int left = query(2*idx+1,low,mid,l,r);
            int right = query(2*idx+2,mid+1,high,l,r);
            return (left + right);
        }
    }
  
    ll func(vector<int>&arr,int n,int m){
        vector<int>psum(n,0);
        for(int i=0;i<n;i++){
            if(arr[i] >= m){
                psum[i]++;
            }else{
                psum[i]--;
            }
        }
        for(int i=1;i<n;i++){
            psum[i] += psum[i-1];
        }
        tree.clear();
        tree.resize(8*n+10);
        BuildSeg(0,0,2*n);
        ll ans = 0LL;
        Update(0,0,2*n,n);
        for(int i=0;i<n;i++){
            int left = 0,  right = psum[i] + n - 1;
            ans += query(0,0,2*n,left,right);
            Update(0,0,2*n,psum[i]+n);
        }
        return ans;
    }
  
    long long countSubarray(int N,vector<int> A,int M) {
        return func(A,N,M) - func(A,N,M+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends