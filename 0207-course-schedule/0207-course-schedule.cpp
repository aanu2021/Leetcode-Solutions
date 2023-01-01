class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans.size()==n;
    }
};