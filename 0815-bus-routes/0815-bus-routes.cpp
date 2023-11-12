class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int,vector<int>>bus_stop_bus;
        unordered_set<int>bus_stop_visited;
        unordered_set<int>bus_visited;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                bus_stop_bus[routes[i][j]].push_back(i);
            }
        }
        
        queue<int>q;
        int lvl = 0;
        
        bus_stop_visited.insert(source);
        q.push(source);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int bus_stop = q.front(); q.pop();
                if(bus_stop == target) return lvl;
                for(int bus : bus_stop_bus[bus_stop]){
                    if(bus_visited.find(bus) != bus_visited.end()) continue;
                    bus_visited.insert(bus);
                    for(int next_bus_stop : routes[bus]){
                        if(bus_stop_visited.find(next_bus_stop) != bus_stop_visited.end()) continue;
                        bus_stop_visited.insert(next_bus_stop);
                        q.push(next_bus_stop);
                    }
                }
            }
            lvl++;
        }
        
        return -1;
        
    }
};