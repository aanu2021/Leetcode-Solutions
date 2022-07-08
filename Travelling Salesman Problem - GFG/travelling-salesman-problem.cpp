// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:

typedef long long ll;

ll n;

ll cost[12][12];

ll dp[12][(1LL<<12)+5];

ll func(ll i,ll bit,ll start){
    
    if(bit==0){
        
        return cost[i][start];
        
    }
    
    if(dp[i][bit]!=-1LL){
        
        return dp[i][bit];
        
    }
    
    ll ans=1e9;
    
    for(ll j=0;j<n;j++){
        
        if((bit&(1LL<<j))!=0){
            
            ans=min(ans,cost[i][j] + func(j,(bit^(1LL<<j)),start));
            
        }
        
    }
    
    return dp[i][bit] = ans;
    
}

int total_cost(vector<vector<int>>c){
  
  n=c.size();
  
  for(ll i=0;i<n;i++){
      for(ll j=0;j<n;j++){
          cost[i][j]=(ll)c[i][j];
      }
  }
  
    ll ans=1e9;
    
    ll currbit=(1LL<<n)-1LL;
    
    for(ll i=0;i<n;i++){
        
        for(ll j=0;j<n;j++){
            for(ll k=0;k<(1LL<<n);k++){
                dp[j][k]=-1LL;
            }
        }
        
        
        ans=min(ans,func(i,(currbit^(1LL<<i)),i));
        
    }
    
    return ans;
  
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends