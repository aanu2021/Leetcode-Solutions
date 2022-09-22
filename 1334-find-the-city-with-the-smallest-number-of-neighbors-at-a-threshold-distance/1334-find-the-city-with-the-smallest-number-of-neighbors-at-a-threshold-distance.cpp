class Solution {
public:
    
    int dijkstra(vector<vector<pair<int,int>>>&graph,int src,int n,int target){
        
        int cnt_nodes=0;
        
        vector<int>dist(n,1e9);
        
        dist[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,src});
        
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int node=curr.second;
            int wt=curr.first;
            
            if(dist[node] > wt){
                
                continue;
                
            }
            
            for(auto nbr:graph[node]){
                
                int v=nbr.first;
                int edge_wt=nbr.second;
                
                if(dist[v] > dist[node] + edge_wt){
                    
                    dist[v] = dist[node] + edge_wt;
                    
                    pq.push({dist[v],v});
                    
                }
                
            }
            
        }
        

        
        for(int i=0;i<n;++i){
            
            if(dist[i] <= target){
                
                cnt_nodes++;
                
            }
            
        }
        
        return cnt_nodes;
        
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int target) {
        
        int min_nodes=1e9;
        int node_no=-1;
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        for(int i=0;i<n;++i){
            
            int currval=dijkstra(graph,i,n,target);
            
            if(currval <= min_nodes){
                
                min_nodes = currval;
                node_no=i;
                
            }
            
        }
        
        return node_no;
        
    }
};