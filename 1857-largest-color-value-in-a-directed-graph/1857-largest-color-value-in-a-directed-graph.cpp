class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.length();
        int maxColor = 0;
        
        vector<vector<int>>graph(n);
        vector<vector<int>>rgraph(n);
        vector<int>indegree(n,0);
        vector<vector<int>>colorCnt(n,vector<int>(26,0));
        vector<int>topo;
        queue<int>q;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];
            graph[u].push_back(v);
            rgraph[v].push_back(u);
            indegree[u]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(int nbr : rgraph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        // for(int u:topo){
        //     cout<<u<<" ";
        // }cout<<"\n";
        if(topo.size() != n) return -1;
        
        for(int u : topo){
            colorCnt[u][colors[u]-'a'] = 1;
            for(int v:graph[u]){
                for(int c=0;c<26;c++){
                    int cnt = 0;
                    if((colors[u]-'a')==c) cnt = 1;
                    colorCnt[u][c] = max(colorCnt[u][c],colorCnt[v][c] + cnt);
                }
            }
        }
        
        for(int u=0;u<n;u++){
            for(int c=0;c<26;c++){
                maxColor = max(maxColor,colorCnt[u][c]);
                // cout<<colorCnt[u][c]<<" ";
             } //cout<<"\n";
        }
        return maxColor;
        
    }
};