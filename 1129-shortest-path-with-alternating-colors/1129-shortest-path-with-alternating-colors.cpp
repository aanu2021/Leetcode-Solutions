class Solution {
public:
    
    vector<int>bfs_red_blue(int n,vector<vector<int>>&red,vector<vector<int>>&blue){
        
        vector<int>red_dist(n,1e9);
        
        vector<int>blue_dist(n,1e9);
        
        red_dist[0]=0;
        
        blue_dist[0]=0;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        q.push({0,1});
        
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int node=curr.first;
            int col=curr.second;
            
            if(col==0){
                
                for(int nbr:blue[node]){
                    
                    if(blue_dist[nbr] > red_dist[node] + 1){
                        
                        q.push({nbr,1});
                        
                        blue_dist[nbr] = red_dist[node] + 1;
                        
                    }
                    
                }
                
            }
            
            else{
                
                 for(int nbr:red[node]){
                    
                    if(red_dist[nbr] > blue_dist[node] + 1){
                        
                        q.push({nbr,0});
                        
                        red_dist[nbr] = blue_dist[node] + 1;
                        
                    }
                    
                }
                
            }
            
        }
        
        vector<int>dist(n,1e9);
        
        for(int i=0;i<n;++i){
            
            dist[i]=min(red_dist[i],blue_dist[i]);
            
            if(dist[i]>=1e9) dist[i]=-1;
            
        }
        
        return dist;
        
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>>rgraph(n);
        
        vector<vector<int>>bgraph(n);
        
        for(int i=0;i<redEdges.size();++i){
            
            rgraph[redEdges[i][0]].push_back(redEdges[i][1]);
            
        }
        
        for(int i=0;i<blueEdges.size();++i){
            
            bgraph[blueEdges[i][0]].push_back(blueEdges[i][1]);
            
        }
        
        return bfs_red_blue(n,rgraph,bgraph);
        
    }
};