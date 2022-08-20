class Solution {
public:
    
    /*
    
     Optimized Approach - Using Heap
     
     The Explanation in the solution section is itself 
     amazing , so you can check that out.
    
    */
    
     /*
     
     Time Complexity  : O(N*logN)
     Space Complexity : O(N)
     
     */
    
     typedef long long ll;
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
       int n=stations.size();
        
       ll distance=0LL;
        
       priority_queue<ll>pq; /* Maxheap that will gonna 
       store the maximum amount of fuel from a particular 
       gas station , provided it is in our range (i.e we can 
       reach the gas-station from our current state using 
       currently stored fuel in our gas tank) */
        
        
       int num_of_refuel_stations=0; 
        
       distance=(ll)startFuel;
        
       int i=0;
        
        
       while(distance<target){
           
           while(i<n && distance>=(ll)stations[i][0]){
               
               pq.push(stations[i][1]);
               
               i++;
               
           }
           
           if(pq.size()==0){ // We are running out of fuel.
               
               return -1;
               
           }
           
           // Otherwise , pick the maximum fuel 
           
           distance+=(ll)pq.top();
           
           pq.pop(); // Once a station's fuel is used , it will never considerable in future.
           
           num_of_refuel_stations++;
           
       } 
        
       return num_of_refuel_stations; 
        
    }
};