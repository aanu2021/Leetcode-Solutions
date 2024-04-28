class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>subtree;
    vector<int>subtree_cnt;
    vector<int>dp;
    
    void precompute(int u, int p){
        subtree_cnt[u]++;
        for(int v : graph[u]){
            if(v == p) continue;
            precompute(v, u);
            subtree_cnt[u] += subtree_cnt[v];
            subtree[u] += (subtree_cnt[v] + subtree[v]);
        }
    }
    
    void dfs(int u, int p, int par){
        int N = subtree_cnt[0];
        dp[u] += (N-subtree_cnt[u]) + par;
        for(int v : graph[u]){
            if(v == p) continue;
            dp[u] += (subtree_cnt[v] + subtree[v]);
        }
        for(int v : graph[u]){
            if(v == p) continue;
            int partial = dp[u] - subtree[v] - subtree_cnt[v];
            dfs(v, u, partial);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        subtree.clear();
        subtree_cnt.clear();
        dp.clear();
        
        graph = vector<vector<int>>(n);
        subtree = vector<int>(n, 0);
        subtree_cnt = vector<int>(n, 0);
        dp = vector<int>(n, 0);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        precompute(0, -1);
        
        dfs(0, -1, 0);
        
        return dp;
    }
};