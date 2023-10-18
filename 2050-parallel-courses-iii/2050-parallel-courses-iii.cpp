class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n,0);
        vector<int>dist(n,0);
        queue<int>q;
        vector<vector<int>>graph(n);
        for(int i=0;i<relations.size();i++){
            int u = relations[i][0];
            int v = relations[i][1];
            u--; v--;
            graph[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0;i<n;i++){
            dist[i] = time[i];
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int &nbr : graph[node]){
                dist[nbr] = max(dist[nbr], dist[node] + time[nbr]);
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};