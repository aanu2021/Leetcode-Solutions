class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        set<int>bus_stop;
        set<int>bus;
        
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        
        queue<int>q;
        
        q.push(source);
        
        int level=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int curr_bus_stop=q.front();
                q.pop();
                
                if(curr_bus_stop==target){
                    return level;
                }
                
                if(bus_stop.find(curr_bus_stop)!=bus_stop.end()){
                    continue;
                }
                
                bus_stop.insert(curr_bus_stop);
                
                for(int buses:mp[curr_bus_stop]){
                    
                    if(bus.find(buses)!=bus.end()){
                        continue;
                    }
                    
                    bus.insert(buses);
                    
                    for(int busstops:routes[buses]){
                        
                        if(bus_stop.find(busstops)!=bus_stop.end()){
                            continue;
                        }
                        
                        q.push(busstops);
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return -1;
        
    }
};