class Solution {
public:
    
    /*
    
    
    Consider the tree as an area of circle , and leaf nodes as
    
    the peripheral of the circle , we start trimming that nodes
    
    from the peripherial of the circle , and then we will reach
    
    the immediate connected nodes of the leaf nodes , at that 
    
    moment all these second-level intermediate nodes are 
    
    considered as a peripheral of the circle , keep on trimming 
    
    them , find out third level nodes , consider them as 
    
    peripheral of circle and continue the process untill and 
    
    unless we visit all the nodes of the tree. Finally we can say
    
    those nodes of which we visit them at the last iteration
    
    (last considered peripheral) , are the minimum height nodes ,
    
    i.e has minimum distance from other nodes. 
    
    
    */
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        
        vector<int>degree(n,0);
        
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++; degree[edges[i][1]]++;
        }
        
        queue<int>q;
        
        vector<int>vis_level(n,0);
        
        int lvl=1; // Iteration index of the peripheral //
        
        for(int i=0;i<n;++i){
            if(degree[i]==1){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int node=q.front(); q.pop();
                
                vis_level[node] = lvl;
                
                for(int nbr:graph[node]){
                    
                    degree[nbr]--;
                    
                    if(degree[nbr]==1){
                        
                        q.push(nbr);
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        vector<int>ans;
        
        int max_level=*max_element(vis_level.begin(),vis_level.end());
        
        for(int i=0;i<n;++i){
            if(vis_level[i]==max_level){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};