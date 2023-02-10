//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    typedef long long ll;
    
    ll totalSum(ll n){
        return (n*(n+1))/2LL;
    }
    
    bool isPossible(ll target,ll K,ll x){
        ll sum = totalSum(K);
        ll currSum = (sum*x);
        if(currSum > target) return false;
        if(fun(x) > target) return false;
        ll temp = fun(x)*K;
        if(temp > target) return false;
        temp *= K;
        if(temp > target) return false;
        if(currSum > target - temp) return false;
        currSum += (((x*(x-1))/2)*(K*K));
        return currSum <= target;
    }
    
    ll fun(ll n){
        return (n*(n-1))/2LL;
    }
  
    vector<long long> distributeCandies(int n, int k) {
        ll low = 0LL , high = (ll)1e8;
        ll ans = 0LL;
        ll N = (ll)n;
        ll K = (ll)k;
        while(low <= high){
            ll mid = (low + high)/2;
            if(isPossible(N,K,mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        //cout<<ans<<"\n";
        vector<ll>answer(K,0LL);
        for(ll i=0;i<K;i++){
            answer[i] += (ll)(i+1)*ans;
            answer[i] += ((ll)K*fun(ans));
        }
        
        ll total = accumulate(answer.begin(),answer.end(),0LL);
        N -= total;
        
        for(ll i=0;i<K;i++){
            ll req = (ans*K);
            req += (i+1);
            req = min(req,N);
            N -= req;
            answer[i] += req;
        }
        
        return answer;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends