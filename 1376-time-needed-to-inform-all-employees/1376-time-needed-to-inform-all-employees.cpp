class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1) continue;
            graph[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        q.push({headID,0});
        
        int maxTimer = 0;
        
        while(!q.empty()){
            
            auto curr = q.front(); q.pop();
            
            int node = curr.first;
            int timer = curr.second;
            
            maxTimer = max(maxTimer,timer);
            
            for(int nbr : graph[node]){
                q.push({nbr,informTime[node] + timer});
            }
            
        }
        
        return maxTimer;
        
    }
};