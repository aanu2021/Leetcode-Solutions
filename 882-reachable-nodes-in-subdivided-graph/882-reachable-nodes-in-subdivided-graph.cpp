class Solution {
public:
    
    /*
    
    Logic : Pick the node with Maximum Remaining Moves , then from there explore all the neighbouring nodes , and decide whether we can visit all the intermediatory nodes or not . If YES , then push the neighbouring node , Else , continue.
    
    */
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<vector<int>>graph(n,vector<int>(n,-1));
        
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
            graph[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        // (Remaining moves , Current Node) //
        
        priority_queue<pair<int,int>>pq;
        
        pq.push({maxMoves,0});
        
        vector<bool>visited(n,false);  // Mark the visited nodes 
        
        int total_vis_nodes = 0;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int node = curr.second;
            int moves = curr.first;
            
            if(visited[node]) continue;
            
            visited[node] = true;
            
            total_vis_nodes++;  // As we visit the current node
            
            for(int nbr=0;nbr<n;nbr++){
                
                if(graph[node][nbr]==-1) continue;
                
                if(moves >= graph[node][nbr] + 1){
                    
                    pq.push({moves-graph[node][nbr]-1,nbr});
                    
                }
                
                int minCost = min(moves,graph[node][nbr]);
                
                graph[node][nbr] -= minCost;
                graph[nbr][node] -= minCost;
                
                total_vis_nodes+=minCost;
                
            }
            
        }
        
        return total_vis_nodes;
        
    }
};