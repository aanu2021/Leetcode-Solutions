/*

Brute Force Approach

*/

class MyCalendarTwo {
public:
    
    vector<vector<int>>v;
    vector<vector<int>>ov;
    
    MyCalendarTwo() {
        
        v.clear();
        ov.clear();
        
    }
    
    bool book(int start, int end) {
        
        for(int i=0;i<ov.size();i++){
            if(start<ov[i][1] && end>ov[i][0]){
                return false;
            }
        }
        
        for(int i=0;i<v.size();i++){
            if(start<v[i][1] && end>v[i][0]){
                ov.push_back({max(start,v[i][0]),min(end,v[i][1])});
            }
        }
       
        v.push_back({start,end});
        
        return true;
        
    }
};

