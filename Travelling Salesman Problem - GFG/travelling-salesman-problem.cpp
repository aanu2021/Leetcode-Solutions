// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:

int n;

int dist[11][11];

int memo[11][1<<11];

int func(int i,int mask){
    
    if(mask==((1<<i)|1)){
        
        return dist[0][i];
        
    }
    
    if(memo[i][mask]!=-1){
        
        return memo[i][mask];
        
    }
    
    int ans=1e9;
    
    for(int j=0;j<n;j++){
        
        if((mask&(1<<j)) && j!=i && j!=0){
            
            ans=min(ans,dist[j][i] + func(j,(mask^(1<<i))));
            
        }
        
    }
    
    return memo[i][mask] = ans;
    
}

 int total_cost(vector<vector<int>>cost){
    
    n=cost.size();
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            dist[i][j]=cost[i][j];
        }
    }
    
    memset(memo,-1,sizeof(memo));
    
    int ans=1e9;
    
    for(int i=0;i<n;i++){
        
        ans=min(ans,dist[i][0] + func(i,(1<<n)-1));
        
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