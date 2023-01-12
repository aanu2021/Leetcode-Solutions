class Solution {
public:
    
    vector<vector<int>>subtree;
    vector<vector<int>>graph;
    vector<int>ans;
    
    void dfs(int u,int p,string &labels){
        subtree[u][labels[u]-'a']++;
        for(int v:graph[u]){
            if(v==p) continue;
            dfs(v,u,labels);
            for(int c=0;c<26;c++){
                subtree[u][c] += subtree[v][c];
            }
        }
        ans[u] = subtree[u][labels[u]-'a'];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        subtree = vector<vector<int>>(n,vector<int>(26,0));
        graph.resize(n);
        ans.resize(n);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(0,-1,labels);
        
        return ans;
    }
};