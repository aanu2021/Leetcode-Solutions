class Solution {
public:

    void dfs(int u,vector<vector<int>>&graph,vector<int>&visited){
        if(visited[u]) return;
        visited[u] = true;
        for(int v=0;v<graph.size();v++){
            if(u==v || visited[v] || graph[u][v]==0) continue;
            dfs(v,graph,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans = 0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            ans++;
            dfs(i,graph,visited);
        }
        return ans;
    }
};