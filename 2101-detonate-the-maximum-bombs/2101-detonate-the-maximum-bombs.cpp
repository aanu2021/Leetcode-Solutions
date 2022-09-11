class Solution {
public:
    
    typedef long long ll;
    
    bool isInside(int x1,int y1,int x2,int y2,int r){
        
        ll distance=((ll)(x2-x1)*(ll)(x2-x1))+((ll)(y2-y1)*(ll)(y2-y1));
        
        return distance<=((ll)r*(ll)r);
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;++i){
            
            for(int j=0;j<n;++j){
                
                if(i==j){
                    continue;
                }
                
                if(isInside(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1],bombs[i][2])){
                    
                    
                    graph[i].push_back(j);
                    
                }
                
            }
            
        }
        
        int maxvalue=0;
        
        for(int i=0;i<n;++i){
            
            vector<bool>visited(n,false);
            
            queue<int>q;
            
            q.push(i);
            
            int currval=0;
            
            while(!q.empty()){
                
                auto node=q.front();
                q.pop();
                
                if(visited[node]){
                    continue;
                }
                
                visited[node]=true;
                
                currval++;
                
                for(int j:graph[node]){
                    
                    if(visited[j]){
                        continue;
                    }
                    
                    q.push(j);
                    
                }
                
            }
            
            maxvalue=max(maxvalue,currval);
            
        }
        
        return maxvalue;
        
    }
};