class Solution {
public:
    
    typedef long long ll;
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n=stations.size();
        
        priority_queue<ll>pq;
        
        ll curr_fuel=(ll)startFuel;
        
        int num_of_stops=0;
        
        int idx=0;
        
        
        while(curr_fuel<target){
            
            while(idx<n && curr_fuel>=(ll)stations[idx][0]){
                
                pq.push(stations[idx][1]);
                
                idx++;
                
            }
            
            if(pq.size()==0){
                
                return -1;
                
            }
            
            ll max_fuel_range=pq.top();
            pq.pop();
            
            curr_fuel+=max_fuel_range;
            
            num_of_stops++;
            
        }
        
        return num_of_stops;
        
    }
};