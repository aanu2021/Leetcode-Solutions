class Solution {
public:
    
    vector<vector<int>>graph;
    int maxPathLen = 0;
    
    int dfs(int u,int p,string &s){
        int internal_path = 0;
        int longest_path = 0;
        int firstc = 0,secondc = 0;
        for(int v:graph[u]){
            if(v==p) continue;
            int next_cand = dfs(v,u,s);
            if(s[u] != s[v]){
                if(next_cand > firstc){
                    secondc = firstc;
                    firstc = next_cand;
                }
                else if(next_cand <= firstc && next_cand >= secondc){
                    secondc = next_cand;
                }
            }
        }
        internal_path = 1 + firstc + secondc;
        longest_path = 1 + firstc;
        maxPathLen = max(maxPathLen,internal_path);
        return longest_path;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        graph.resize(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1) continue;
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
        dfs(0,-1,s);
        return maxPathLen;
    }
};