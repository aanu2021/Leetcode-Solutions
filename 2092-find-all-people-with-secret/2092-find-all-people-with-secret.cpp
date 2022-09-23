class Solution {
public:
    
    struct comp{
      
        bool operator()(const pair<int,int>&x,const pair<int,int>&y){
            
            return x.second > y.second;
            
        }
        
    };
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<bool>visited(n,false);
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<meetings.size();++i){
            
            graph[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            
            graph[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        pq.push({0,0});
        pq.push({firstPerson,0});
        
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int curr_node=curr.first;
            int curr_timer=curr.second;
            
            if(visited[curr_node]) continue;
            
            visited[curr_node] = true;
            
            for(auto nbrs : graph[curr_node]){
                
                int nbr = nbrs.first;
                int reach_timer = nbrs.second;
                
                if(visited[nbr]) continue;
                
                if(curr_timer > reach_timer) continue;
                
                pq.push({nbr,reach_timer});
                
            }
            
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;++i) {
            
            if(visited[i]) ans.push_back(i);
            
        }
        
        return ans;
        
    }
};