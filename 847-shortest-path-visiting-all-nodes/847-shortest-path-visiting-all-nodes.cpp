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
            
            if(visited.find({curr.node,curr.mask})!=visited.end()){
                
                continue;
                
            }
            
            if(curr.mask==allMask){
                
                return curr.cost;
                
            }
            
            visited.insert({curr.node,curr.mask});
            
            for(int nbr:graph[curr.node]){
                
                int newMask=(curr.mask)|(1<<nbr);
                
                q.push({nbr,newMask,curr.cost+1});
                
            }
            
        }
        
        return -1;
        
    }
};