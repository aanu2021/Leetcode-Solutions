class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(int x1,int y1,int x2,int y2,int r){
        
        ll distance = (ll)((ll)(x2-x1)*(ll)(x2-x1)) + (ll)((ll)(y2-y1)*(ll)(y2-y1)); 
        
        ll haveDistance = (ll)(r)*(ll)(r);
        
        return distance <= haveDistance;
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isPossible(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1],bombs[i][2])){
                    graph[i].push_back(j);
                }
            }
        }
        
        vector<int>visited(n,0);
        int maxBombs = 0;
        
        for(int src=0;src<n;src++){
            
            queue<int>q;
            
            for(int i=0;i<n;i++) visited[i] = 0;
            
            q.push(src);
            visited[src] = 1;
            
            int currBombs = 0;
            
            while(!q.empty()){
                
                int node = q.front();
                q.pop();
                currBombs++;
                
                for(int nbr : graph[node]){
                    
                    if(visited[nbr]) continue;
                    visited[nbr] = 1;
                    q.push(nbr);
                    
                }
            }
            
            maxBombs = max(maxBombs,currBombs);
            
            if(maxBombs == n) return n;
            
        }
        
        return maxBombs;
        
    }
};

    
    
