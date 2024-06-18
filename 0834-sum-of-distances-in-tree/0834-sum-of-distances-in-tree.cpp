class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>subtree_cnt;
    vector<int>subtree_sum;
    vector<int>dp;
    
    void precompute(int u, int p){
        subtree_cnt[u]++;
        for(int v : graph[u]){
            if(v == p) continue;
            precompute(v, u);
            subtree_cnt[u] += subtree_cnt[v];
            subtree_sum[u] += subtree_sum[v] + subtree_cnt[v];
        }
    }
    
    void dfs(int u, int p, int par){
        dp[u] = subtree_sum[u] + (subtree_cnt[0] - subtree_cnt[u]) + par;
        for(int v : graph[u]){
            if(v == p) continue;
            int partial = dp[u] - subtree_sum[v] - subtree_cnt[v];
            dfs(v, u, partial);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        graph.clear();
        subtree_cnt.clear();
        subtree_sum.clear();
        dp.clear();
        
        graph = vector<vector<int>>(n);
        subtree_cnt = vector<int>(n, 0);
        subtree_sum = vector<int>(n, 0);
        dp = vector<int>(n, 0);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        precompute(0, -1);
        dfs(0, -1, 0);
        
        return dp;
        
    }
};