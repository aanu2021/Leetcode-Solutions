//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

typedef long long int ll;

class Solution
{
    public:
    
        bool isPossible(vector<int>&arr,int n,int k,int w,ll mid){
            vector<ll>reqd(n,0LL);
            vector<ll>prefix(n+1,0LL);
            for(int i=0;i<n;i++){
                reqd[i] = max(0LL,mid-arr[i]);
            }
            // cout<<mid<<"\n";
            // for(ll ele:reqd){
            //     cout<<ele<<" ";
            // }cout<<"\n";
            ll currSum = 0LL;
            for(int i=0;i<n;i++){
                if(i > 0) prefix[i] += prefix[i-1];
                ll currHave = max(0LL,reqd[i] - prefix[i]);
                currSum += currHave;
                prefix[i] += currHave;
                if(i + w < n) prefix[i+w] -= currHave;
            }
            // for(int i=0;i<n;i++){
            //     cout<<prefix[i]<<" ";
            // }cout<<"\n";
            if(currSum <= k) return true;
            else return false;
        }
    
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &arr)
        {
            
            ll low = *min_element(arr.begin(),arr.end());
            ll high = *max_element(arr.begin(),arr.end()) + k;
            ll ans = -1LL;
            while(low <= high){
                ll mid = low + (high-low)/2;
                if(isPossible(arr,n,k,w,mid)){
                    ans = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return ans;
            
        }
};

/*

2 2 2 2 1 1
0 0 0 0 1 1

w = 3
k = 7

req : [0 0 0 0 1 1]
dp  : [2 0 5 3 1 0 4]
       0 0 3 3 1 0 4
       0 0 0 0 0 0 4
       

low = 1
high = 4
mid = 2

*/


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends