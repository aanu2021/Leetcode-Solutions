class Solution {
public:
    
    vector<int>BFS(int n,vector<vector<int>>&graph,int src){
        vector<int>dist(n,1e9);
        int lvl = 0;
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                dist[node] = lvl;
                for(int nbr:graph[node]){
                    if(visited[nbr]) continue;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
            lvl++;
        }
        return dist;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1) continue;
            graph[i].push_back(edges[i]);
        }
        vector<int>dist1 = BFS(n,graph,node1);
        vector<int>dist2 = BFS(n,graph,node2);
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int d1 = dist1[i];
            int d2 = dist2[i];
            if(d1 >= 1e9 || d2 >= 1e9) continue;
            ans = min(ans,max(d1,d2));
        }
        if(ans >= 1e9) return -1;
        for(int i=0;i<n;i++){
            int d1 = dist1[i];
            int d2 = dist2[i];
            if(d1 >= 1e9 || d2 >= 1e9) continue;
            int curr = max(d1,d2);
            if(curr == ans) return i;
        }
        return -1;
    }
};