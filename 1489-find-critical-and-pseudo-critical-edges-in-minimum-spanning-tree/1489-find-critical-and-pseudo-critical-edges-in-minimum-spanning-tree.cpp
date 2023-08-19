class Solution {
public:
    
    int MST(vector<unordered_map<int,int>>&graph,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        int sum = 0;
        vector<bool>visited(n,false);    
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(visited[node]) continue;
            visited[node] = true;
            sum += wt;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                if(visited[nbr]) continue;
                pq.push({edgeWt,nbr});
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return 1e9;
            }
        }
        
        return sum;
        
    }
    
    int MST2(vector<unordered_map<int,int>>&graph,int n,int u,int v,int w){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,u});
        pq.push({0,v});
        int sum = w;
        vector<bool>visited(n,false);    
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(visited[node]) continue;
            visited[node] = true;
            sum += wt;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                if(visited[nbr]) continue;
                pq.push({edgeWt,nbr});
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return 1e9;
            }
        }
        
        return sum;
        
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<unordered_map<int,int>>graph(n);
        int m = edges.size();
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        int mstSum = MST(graph,n);
        
        vector<vector<int>>answer(2);
        vector<int>critical(m,0);
        vector<int>not_part_MST(m,0);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].erase(v);
            graph[v].erase(u);
            int currSum = MST(graph,n);
            if(currSum > mstSum){
                critical[i] = 1;
            }
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        for(int i=0;i<m;i++){
            if(critical[i]==1) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            int currSum = MST2(graph,n,u,v,w);
            // cout<<currSum<<"\n";
            if(currSum > mstSum){
                not_part_MST[i] = 1;
            }
        }
        
        for(int i=0;i<m;i++){
            if(critical[i]==1){
                answer[0].push_back(i);
            }
            else if(critical[i]==0 && not_part_MST[i]==0){
                answer[1].push_back(i);
            }
        }
        
        return answer;
        
    }
};

/*

first find out the MST of the graph

critical edge

for all possible edges remove it from the graph.
calculate the MST again for the graph, if it remains the same,
then the removed edge is not critical edges.

pseudo-critical edge

after selecting critical edges, all the remaining edges are pseudo-critical edges.

*/