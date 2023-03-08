//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool func(int u,vector<vector<int>>&G,vector<int>&appName,vector<int>&vis){
        for(int v=0;v<G[0].size();v++){
            if(G[u][v] && !vis[v]){
                vis[v] = 1;
                if(appName[v] < 0 || func(appName[v],G,appName,vis)){
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
	    vector<int>appName(n,-1);
	    int ans = 0;
	    for(int i=0;i<m;i++){
	        vector<int>vis(n,0);
	        if(func(i,G,appName,vis)) ans++;
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