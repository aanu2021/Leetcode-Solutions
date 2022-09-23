struct Pair{
  
    int node;
    int mask;
    int cost;
    
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        int allMask=(1<<n)-1;
        
        set<pair<int,int>>visited;
        
        queue<Pair>q;
        
        for(int i=0;i<n;++i){
            
            int currMask=(1<<i);
            
            q.push({i,currMask,0});
            
        }
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int node=curr.node;
            int currMask=curr.mask;
            int currCost=curr.cost;
            
            if(visited.find({node,currMask})!=visited.end()){
                
                continue;
                
            }
            
            visited.insert({node,currMask});
            
            if(currMask==allMask) return currCost;
            
            for(int nbr:graph[node]){
                
                int nbrMask=(currMask|(1<<nbr));
                
                q.push({nbr,nbrMask,1 + currCost});
                
            }
            
        }
        
        return -1;
        
    }
};