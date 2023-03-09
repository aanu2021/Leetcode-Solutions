class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>vis;
    vector<int>timer;
    
    void dfs(int u,int t,int &maxLen){
        vis[u] = 1;
        timer[u] = t;
        for(int v:graph[u]){
            if(vis[v]){
                if(timer[v]){
                    maxLen = max(maxLen,timer[u]-timer[v]+1);
                }
            }
            else{
                dfs(v,t+1,maxLen);
            }
        }
        timer[u] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        graph.clear();
        vis.clear();
        timer.clear();
        
        graph.resize(n);
        vis.resize(n,0);
        timer.resize(n,0);
        
        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1) continue;
            graph[i].push_back(edges[i]);
        }
        
        int maxLen = -1;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,1,maxLen);
        }
        return maxLen;
    }
};