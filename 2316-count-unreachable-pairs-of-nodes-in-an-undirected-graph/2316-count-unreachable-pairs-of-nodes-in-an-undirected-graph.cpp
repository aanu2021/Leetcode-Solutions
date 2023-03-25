class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>>graph;
    vector<int>visited;
    
    void dfs(int u,int &comp){
        visited[u] = 1;
        comp++;
        for(int v:graph[u]){
            if(visited[v]) continue;
            dfs(v,comp);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        ll ans = 0LL;
        
        graph.resize(n);
        visited.resize(n,0);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int comp = 0;
            dfs(i,comp);
            ans += (ll)((ll)comp*(ll)(n-comp));
        }
        
        return ans/2;
        
    }
};    