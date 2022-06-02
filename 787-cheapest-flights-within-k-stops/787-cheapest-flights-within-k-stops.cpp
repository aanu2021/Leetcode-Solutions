class Solution {
public:
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int>dist(n,1e9);
        
        dist[src]=0;
        
        k++;
        
        queue<pair<int,int>>q;
        
        q.push({src,0});
        
        
        while(!q.empty() && k>0){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int node=curr.first;
                int wt=curr.second;
                
                if(dist[node]>wt){
                    continue;
                }
                
                for(auto j:graph[node]){
                    
                    if(dist[j.first]>wt+j.second){
                        dist[j.first]=wt+j.second;
                        q.push({j.first,dist[j.first]});
                    }
                    
                }
                
            }
            
            k--;
            
        }
        
        
        if(dist[dst]<1e9){
            return dist[dst];
        }else{
            return -1;
        }
        
    }
};