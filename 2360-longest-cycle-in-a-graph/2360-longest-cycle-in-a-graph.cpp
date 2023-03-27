class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>timer;
    vector<int>vis;
    
    void dfs(int u,int tim,int &maxLen){
        vis[u] = 1;
        timer[u] = tim;
        for(int v:graph[u]){
            if(vis[v]){
                if(timer[v]){
                    maxLen = max(maxLen,timer[u]-timer[v]+1);
                }
            }
            else{
                dfs(v,tim+1,maxLen);
            }
        }
        timer[u] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
       
        int n = edges.size();
        
        graph.resize(n);
        timer.resize(n,0);
        vis.resize(n,0);
        
        for(int i=0;i<n;i++){
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