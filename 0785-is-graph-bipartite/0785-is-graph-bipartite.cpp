class Solution {
public:
    
    bool check(int u,vector<vector<int>>&graph,vector<int>&color){
        for(int v:graph[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                bool flag = check(v,graph,color);
                if(!flag) return false;
            }
            else if(color[v]==color[u]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 0;
                bool flag = check(i,graph,color);
                if(!flag) return false;
            }
        }
        return true;
    }
};