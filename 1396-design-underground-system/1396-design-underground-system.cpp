class UndergroundSystem {
public:
    
    unordered_map<int,pair<string,int>>check_In;
    unordered_map<string,pair<int,int>>routeMap;
    
    UndergroundSystem() {
        check_In.clear();
        routeMap.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        check_In[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto check = check_In[id];
        string start = check.first;
        int stime = check.second;
        check_In.erase(id);
        
        string currRoute = start + "->" + stationName;
        routeMap[currRoute].first += (t-stime);
        routeMap[currRoute].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {      
        string currRoute = startStation + "->" + endStation;
        return (routeMap[currRoute].first*1.0)/routeMap[currRoute].second;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */