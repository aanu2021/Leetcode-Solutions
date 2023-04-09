class Solution {
public:
    
    vector<vector<int>>dp;
    vector<vector<int>>graph;
    vector<int>visited;
    vector<int>pathVis;
    vector<int>comp;
    
    bool isCycle(int u){
        visited[u] = 1;
        pathVis[u] = 1;
        for(int v:graph[u]){
            if(visited[v]){
                if(pathVis[v]) return true;
            }
            else{
                bool flag = isCycle(v);
                if(flag) return true;
            }
        }
        pathVis[u] = 0;
        return false;
    }
    
    int func(string &colors,int node,int col){
        if(dp[node][col] != -1) return dp[node][col];
        int currVal = (((colors[node]-'a')==col) ? 1 : 0);
        int ans = currVal;
        for(int nbr:graph[node]){
            ans = max(ans,func(colors,nbr,col) + currVal);
        }
        return dp[node][col] = ans;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        graph.resize(n);
        visited.resize(n,0);
        pathVis.resize(n,0);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            comp.push_back(i);
            if(isCycle(i)) return -1;
        }
        
        dp = vector<vector<int>>(n,vector<int>(26,-1));
        int maxColor = 0;
        
        for(int node : comp){
            for(int col=0;col<26;col++){
                maxColor = max(maxColor,func(colors,node,col));
            }
        }      
        return maxColor;
        
    }
};