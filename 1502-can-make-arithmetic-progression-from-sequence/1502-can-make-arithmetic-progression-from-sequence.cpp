class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
       
        int n = arr.size();
        
        int minValue = arr[0];
        int maxValue = arr[0];
        
        for(int i=1;i<n;i++){
            minValue = min(minValue,arr[i]);
            maxValue = max(maxValue,arr[i]);
        }
        
        if((maxValue-minValue)%(n-1) != 0) return false;
        
        int d = (maxValue - minValue)/(n - 1);
        
        int i=0;
        
        for(;i<n;){
            if(arr[i] == minValue + (i*d)){
                i++;
                continue;
            }
            else if((arr[i]-minValue)%d != 0){
                return false;
            }
            else{
                int j = (arr[i] - minValue)/d;
                if(arr[i] == arr[j]){
                    return false;
                }
                swap(arr[i],arr[j]);
            }
        }
        
        return true;
    }
};


    
    