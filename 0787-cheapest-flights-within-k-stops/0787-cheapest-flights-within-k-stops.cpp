class Solution {
public:
    
    /*
    
    Approach : BFS
    Time Complexity  : O(N + E*K)
    Space Complexity : O(N)
    
    */
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        } 
        
        queue<pair<int,int>>q;
        q.push({src,0});
        k++;
        
        vector<int>dist(n,1e9);
        dist[src] = 0;
        
        int lvl = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto curr = q.front();
                q.pop();
                
                int node = curr.first;
                int distance = curr.second;
                
                if(lvl == k) continue;
                
                for(auto &nbrs:graph[node]){
                    int nbr = nbrs.first;
                    int edgeWt = nbrs.second;
                    if(dist[nbr] >= distance + edgeWt){
                        dist[nbr] = distance + edgeWt;
                        q.push({nbr,dist[nbr]});
                    }
                }
                
            }
            
            lvl++;
            
        }
        
        return dist[dst] >= 1e9 ? -1 : dist[dst];
        
    }
    
    /*
    
    Approach : Bellman Ford Algorithm
    Time Complexity  : O((N + E) * K)
    Space Complexity : O(N)
    
    */
    
    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>price(n,1e9);
        vector<int>tempPrice(n,1e9);
        tempPrice[src] = 0;
        price[src] = 0;
        
        k++;
        
        for(int i=1;i<=k;i++){
            
            for(int j=0;j<flights.size();j++){
                
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                
                if(price[u] + wt <= tempPrice[v]){
                    tempPrice[v] = price[u] + wt;
                }
                
            }
            
            for(int j=0;j<n;j++){
                
                price[j] = tempPrice[j];
                
            }
            
        }
        
        return price[dst] >= 1e9 ? -1 : price[dst];
        
    }
    
};