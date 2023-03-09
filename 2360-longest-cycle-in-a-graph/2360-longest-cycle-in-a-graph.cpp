class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>vis;
    vector<int>tim;
    
    void dfs(int u,int p,int t,int &maxLen){
        if(vis[u]) return;
        vis[u] = 1;
        tim[u] = t;
        for(int v:graph[u]){
            if(vis[v]){
                if(tim[v]){
                    maxLen = max(maxLen,tim[u]-tim[v]+1);
                }
            }
            else{
                dfs(v,u,t+1,maxLen);
            }
        }
        tim[u] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        graph.clear();
        vis.clear();
        tim.clear();
        
        graph.resize(n);
        vis.resize(n,0);
        tim.resize(n,0);
        
        for(int i=0;i<n;i++){
            if(edges[i] == -1) continue;
            graph[i].push_back(edges[i]);
        }
        
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,-1,1,maxLen);
        }
        return maxLen==0 ? -1 : maxLen;
    }
};