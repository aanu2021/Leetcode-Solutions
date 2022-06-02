class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        set<int>bus_no;
        set<int>bus_stop_no;
        
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        
        // Bus --> Bus-Stops
        // Bus-Stops --> Buses
        
        queue<int>q;
        
        int level=0;
        
        q.push(source);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int curr_bus_stop=q.front();
                q.pop();
                
                if(bus_stop_no.find(curr_bus_stop)!=bus_stop_no.end()){
                    continue;
                }
                
                bus_stop_no.insert(curr_bus_stop);
                
                if(curr_bus_stop==target){
                    return level;
                }
                
                for(int all_bus:mp[curr_bus_stop]){
                    
                    if(bus_no.find(all_bus)!=bus_no.end()){
                        continue;
                    }
                    
                    bus_no.insert(all_bus);
                    
                    for(int bus_stops:routes[all_bus]){
                        
                        if(bus_stop_no.find(bus_stops)!=bus_stop_no.end()){
                            continue;
                        }
                        
                        q.push(bus_stops);
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return -1;
        
    }
};