class Solution {
public:
    
    vector<vector<int>>graph;
    
    int N;
    
    vector<int>subtree_dist;
    
    vector<int>subtree_count;
    
    vector<int>ans;
    
    
    
    void precompute(int u,int p){
        
        subtree_count[u]=1;
        subtree_dist[u]=0;
        
        for(int v:graph[u]){
            
            if(v==p){
                continue;
            }
            
            precompute(v,u);
            
            subtree_count[u]+=subtree_count[v];
            
            subtree_dist[u]+=(subtree_count[v] + subtree_dist[v]);
            
        }
        
    }
    
    
    void func(int u,int p,int partial){
        
        ans[u]=subtree_dist[u]+(N-subtree_count[u])+partial;
        
        for(int nbr:graph[u]){
            
            if(nbr==p){
                continue;
            }
            
            int curr_partial_for_nbr=ans[u]-(subtree_count[nbr]+subtree_dist[nbr]);
            
            func(nbr,u,curr_partial_for_nbr);
            
        }
        
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N=0;
        
        graph.resize(n);
        
        ans.resize(n,0);
        
        subtree_dist.resize(n,0);
        
        subtree_count.resize(n,0);
        
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        // Precomputation for subtree_count and subtree_dist
        
        precompute(0,-1);
        
        N=subtree_count[0];
        
        // Utility function to go for an euler tour and using re-rooting technique to determine the distance of all the nodes from a given node.
        
        func(0,-1,0);
        
        
        return ans;
        
    }
};