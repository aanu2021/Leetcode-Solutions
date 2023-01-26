class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        k++;
        queue<pair<int,int>>q;
        q.push({src,0});
        
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
};