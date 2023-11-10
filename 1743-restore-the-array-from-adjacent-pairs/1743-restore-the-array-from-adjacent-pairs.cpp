class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& p) {
        int n = p.size();
        n++;
        vector<int>answer;
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<p.size();i++){
            int u = p[i][0];
            int v = p[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int src = -1;
        for(auto &itr : graph){
            if(itr.second.size() == 1){
                src = itr.first;
                break;
            }
        }
        unordered_map<int,int>visited;
        queue<int>q;
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int node = q.front(); q.pop();
            answer.push_back(node);
            for(auto &nbr : graph[node]){
                if(visited[nbr]) continue;
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
        return answer;
    }
};