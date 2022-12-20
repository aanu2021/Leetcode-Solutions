//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    typedef long long ll;
    const ll M = 1e9 + 7;
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    

    int countBits(int n, long long int A[])
    {
        
        ll ans = 0LL;
        
        vector<ll>prefix(32,0LL);
        
        for(int i=0;i<n;i++){
            for(int j=31;j>=0;j--){
                if((A[i]&(1LL<<j))){
                    prefix[j]++;
                }
            }
        }
        
        for(int i=0;i<32;i++){
            ll cnt_one = prefix[i];
            ll cnt_zer = (n-prefix[i]);
            ll curr = mul(cnt_one,cnt_zer);
            curr = mul(2LL,curr);
            ans = add(ans,curr);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends