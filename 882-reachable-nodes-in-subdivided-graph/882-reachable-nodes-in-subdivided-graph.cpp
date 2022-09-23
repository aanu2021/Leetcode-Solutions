class Solution {
public:
    
    /*
    
    Logic : Pick the node with Maximum Remaining Moves , then from there explore all the neighbouring nodes , and decide whether we can visit all the intermediatory nodes or not . If YES , then push the neighbouring node , Else , continue.
    
    */
    
    /*
    
    Time Complexity  : O(E*log(V))
    Space Complexity : O(V)
    
    */
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        unordered_map<int,unordered_map<int,int>>graph;
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
            graph[edges[i][1]][edges[i][0]]=edges[i][2];
            
        }
        
        vector<bool>visited(n,false);
        
        int total_vis_nodes = 0;
        
        priority_queue<pair<int,int>>pq;
        
        pq.push({maxMoves,0});
        
        while(!pq.empty()){
            
            auto curr=pq.top();pq.pop();
            
            int node=curr.second;
            int moves=curr.first;
            
            if(visited[node]) continue;
            
            visited[node] = true;
            
            total_vis_nodes++;
            
            
            for(auto nbrs : graph[node]){
                
                int nbr = nbrs.first;
                
                if(!visited[nbr] && moves >= 1+graph[node][nbr]){
                    
                    pq.push({moves-graph[node][nbr]-1,nbr});
                    
                }
                
                int minCost=min(moves,graph[node][nbr]);
                
                graph[node][nbr] -= minCost;
                graph[nbr][node] -= minCost;
                
                total_vis_nodes += minCost;
                
            }
            
        }
        
        return total_vis_nodes;
        
    }
};