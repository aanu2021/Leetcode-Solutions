/*

Approach : Optimized Approach

Use a set<pair<int,int>> container that will store the valid intervals [start , end] 

T.C : O(N*logN)
S.C : O(N)

*/

class MyCalendar {
public:
    
    // Container that will store the starting point and ending point of the intervals //
    
    set<pair<int,int>>S;
    
    MyCalendar() {
        
        S.clear();
        
    }
    
    bool book(int start, int end) {
        
        const pair<int,int>event{start,end};
        
        const auto nextEvent = S.lower_bound(event);
        
        if(nextEvent!=S.end()){
            
            if(nextEvent->first < end){
                return false;
            }
            
        }
        
        if(nextEvent!=S.begin()){
            
            const auto prevEvent = prev(nextEvent);
            
            if(prevEvent->second > start){
                return false;
            }
            
        }
        
        S.insert(event);
        
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */