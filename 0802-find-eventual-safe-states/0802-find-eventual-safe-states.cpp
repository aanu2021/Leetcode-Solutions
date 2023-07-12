class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>indegree(n,0);
        vector<vector<int>>rgraph(n);
        
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                rgraph[j].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>safe_vis(n,0);
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            safe_vis[node] = 1;
            for(int nbr : rgraph[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        vector<int>answer;
        
        for(int i=0;i<n;i++){
            if(safe_vis[i]) answer.push_back(i);
        }
        
        return answer;
        
    }
};