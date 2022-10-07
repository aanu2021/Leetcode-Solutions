/*

Goal : Maximum value of overlapped intervals at some points each time after adding a new interval.How many intervals cover a single point ???

Approach : Sweep Line Algorithm [Differential Array]

T.c : O(N^2)
S.C : O(N)

*/

class MyCalendarThree {
public:
    
    map<int,int>diff;
    
    MyCalendarThree() {
        
        diff.clear();
        
    }
    
    int book(int start, int end) {
        
        diff[start]++;
        diff[end]--;
        
        int curr = 0;
        int maxi = 0;
        
        for(auto itr:diff){
            
            curr += itr.second;
            maxi = max(maxi,curr);
            
        }
        
        return maxi;
        
    }
};

    

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */