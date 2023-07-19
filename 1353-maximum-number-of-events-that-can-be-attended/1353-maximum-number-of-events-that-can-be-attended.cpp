/*


Approach : Greedy + Observation

Observation + Algorithm :

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
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int MAX = 0;
        for(int i=0;i<n;i++){
            MAX = max(MAX, events[i][1]);
        }
        
        vector<vector<int>>startTime(MAX+1);
        for(int i=0;i<n;i++){
            startTime[events[i][0]].push_back(events[i][1]);
        }
        
        int events_attended = 0;
        
        for(int i=0;i<=MAX;i++){
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            for(int ele : startTime[i]){
                pq.push(ele);
            }
            if(!pq.empty()){
                pq.pop();
                events_attended++;
            }
        }
        
        return events_attended;
        
    }
};