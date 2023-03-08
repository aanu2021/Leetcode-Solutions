//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<bool>vis;
    vector<int>appName;
    
    bool func(int u,vector<vector<int>>&G){
        for(int v=0;v<G[u].size();v++){
            if(G[u][v] && !vis[v]){
                vis[v] = true;
                if(appName[v]==-1 || func(appName[v],G)){
                    appName[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&G){
	    int m = G.size();
	    int n = G[0].size();
	    int N = max(m,n);
	    appName.clear();
	    int ans = 0;
	    appName.assign(N,-1);
	    for(int i=0;i<m;i++){
	        vis.assign(N,false);
	        if(func(i,G)) ans++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends