class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int index=0;
        
        int total=0;
        
        int tank=0;
        
        for(int i=0;i<gas.size();++i){
            
            int consume=(gas[i]-cost[i]);
            
            tank+=consume;
            
            if(tank<0){
                
                tank=0;
                
                index=i+1;
                
            }
            
            total+=consume;
            
        }
        
        return total < 0 ? -1 : index;
        
    }
};