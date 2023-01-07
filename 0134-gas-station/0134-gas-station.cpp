class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int tank = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            int consume = gas[i] - cost[i];
            tank += consume;
            total += consume;
            if(tank < 0){
                tank = 0;
                index = i+1;
            }
        }
        if(total < 0) return -1;
        else return index;
    }
};