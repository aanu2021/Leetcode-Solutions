class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int>color(n,-1);
            
        bool flag=true;
        
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            
            if(visited[i]==true){
                continue;
            }
            
            queue<pair<int,int>>q;
            
            q.push({i,0});
          
          while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int node=curr.first;
            int curr_color=curr.second;
            
            if(visited[node]==true){
                continue;
            }
            
            visited[node]=true;
            
            color[node]=curr_color;
            
            for(int j:graph[node]){
                
                if(visited[j]==false){
                    q.push({j,!curr_color});
                }
                
                else{
                    
                    if(color[j]==color[node]){
                        flag=false;
                        break;
                    }
                    
                }
                
            }
            
            if(flag==false){
                break;
            }
            
        }
            
            if(flag==false){
                break;
            }
            
      }
        
        
        return flag;
        
    }
};