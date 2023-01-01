class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>parent;
    vector<int>dist;
    vector<int>value;
    
    void dfs1(int u,int p,int lvl){
        parent[u] = p;
        dist[u] = lvl;
        for(int v:graph[u]){
            if(v==p) continue;
            dfs1(v,u,lvl+1);
        }
    }
    
    int dfs2(int u,int p){
        int curr = value[u];
        int maxi = -1e9;
        for(int v:graph[u]){
            if(v==p) continue;
            maxi = max(maxi,dfs2(v,u));
        }
        if(maxi==-1e9) return curr;
        else return curr + maxi;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        
        graph.resize(n);
        parent.resize(n,-1);
        dist.resize(n,0);
        value.resize(n);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }   
        
        dfs1(0,-1,0);
        
        int bob_dist = 0;
        
        while(bob!=0){
            if(bob_dist < dist[bob]) amount[bob] = 0;
            else if(bob_dist == dist[bob]) amount[bob]/=2;
            bob = parent[bob];
            bob_dist++;
        }
        
        for(int i=0;i<n;i++){
            value[i] = amount[i];
        }
        
        return dfs2(0,-1);
        
    }
};