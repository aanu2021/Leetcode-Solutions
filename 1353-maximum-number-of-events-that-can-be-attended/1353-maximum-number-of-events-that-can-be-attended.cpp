/*


Approach : Greedy + Observation

Observation :

1. For two events with same starting time , we will select that 
one which has the minimum ending time , that is left with the
liberty to take those ones which has comparatably greater ending 
time.


2. If we are assuming for a Data Structure , which will indicate
the currently activated (means current day d is in between their
starting and ending times) , and after their ending time being 
finished we will surely remove those currently inactive events.


3. Priority Queue (With Min Heap Property) is the efficient DS ,
that will help us to solve these problem . At day 'd' , we will 
insert all the events with their respective starting time 'd'.


4. Again we need to check whther among those events (currently
inside the heap) had been passed its ending time or not , if yes
, then remove them from the heap.


5. After Step '3' and '4' , we will attend a event (that is 
present at the top of the minheap i.e with minimum ending time), 
and increment our answer by 1.


6. Okay now the only problem left with us , is how we will 
efficiently insert the events with equal starting time in our
heap . For these we can sort the events vector in the ascending 
order of their starting time .


T.C : O(N*logN)
S.C : O(N)


*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        
        int events_attend = 0;
        
        sort(events.begin(),events.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i = 0;
        
        for(int d=1;d<=100002;d++){
            
            while(i<n && events[i][0]==d){
                
                pq.push(events[i][1]);
                i++;
                
            }
            
            while(!pq.empty() && pq.top() < d){
                
                pq.pop();
                
            }
            
            if(!pq.empty()){
                
                pq.pop();
                events_attend++;
                
            }
            
        }
        
        return events_attend;
        
    }
};