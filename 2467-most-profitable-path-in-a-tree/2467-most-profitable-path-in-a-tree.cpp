class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>amount;
    vector<int>parent;
    vector<int>dist;
    vector<int>subtree;
    
    void precompute(int u,int p,int lvl){
        parent[u] = p;
        dist[u] = lvl;
        for(int v : graph[u]){
            if(v == p) continue;
            precompute(v,u,lvl+1);
        }
    }
    
    int dfs(int u,int p){
        int nbr = INT_MIN;
        int currNodeVal = amount[u];
        for(int v : graph[u]){
            if(v == p) continue;
            nbr = max(nbr,dfs(v,u));
        }
        if(nbr == INT_MIN) return currNodeVal;
        else return currNodeVal + nbr;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        int n = amt.size();
        graph.resize(n);
        amount.resize(n);
        dist.resize(n,0);
        parent.resize(n,-1);
        subtree.resize(n,0);
        for(int i=0;i<n;i++){
            amount[i] = amt[i];
        }
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        precompute(0,-1,0);
        int lvl = 0;
        while(bob != -1){
            int aliceLevel = dist[bob];
            int bobLevel = lvl;
            if(aliceLevel > bobLevel){
                amount[bob] = 0;
            }
            else if(aliceLevel == bobLevel){
                amount[bob] /= 2;
            }
            bob = parent[bob];
            lvl++;
        }
        return dfs(0,-1);
    }
};