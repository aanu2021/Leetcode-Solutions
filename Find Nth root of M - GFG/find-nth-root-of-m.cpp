//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	typedef long long ll;
	
	const ll M = 1000000000;
	
   ll func(ll a,ll b){
	    ll res = 1LL;
	    for(ll i=1;i<=b;i++){
	        res *= a;
	        if(res > M){
	            return 1e18;
	        }
	    }
	    return res;
	}
	
	int NthRoot(int nn, int mm)
	{
	    ll n = (ll)nn;
	    ll m = (ll)mm;
	    
	    ll low = 1LL, high = m;
	    while(low <= high){
	        ll mid = (low + high)/2;
	        ll prod = func(mid,n);
	        if(prod == m){
	            return (int)mid;
	        }
	        else if(prod > m){
	            high = mid - 1;
	        }
	        else{
	            low = mid + 1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends