class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<unordered_set<int>>graph(n+1);
        
        for(int i=0;i<paths.size();++i){
            
            graph[paths[i][0]].insert(paths[i][1]);
            graph[paths[i][1]].insert(paths[i][0]);
            
        }
        
        vector<int>color(n+1,-1);
        
        for(int i=1;i<=n;++i){
            
            set<int>S;
            
            for(int nbr:graph[i]){
                
                if(color[nbr]!=-1){
                    
                    S.insert(color[nbr]);
                    
                }
                
            }
            
            for(int col=1;col<=4;col++){
                
                if(S.find(col)==S.end()){
                    
                    color[i]=col;
                    break;
                    
                }
                
            }
            
        }
        
        reverse(color.begin(),color.end());
        
        color.pop_back();
        
        reverse(color.begin(),color.end());
        
        return color;
        
    }
};