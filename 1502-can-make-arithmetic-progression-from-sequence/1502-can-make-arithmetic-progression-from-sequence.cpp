class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();
        
        int minValue = *min_element(arr.begin(),arr.end());
        int maxValue = *max_element(arr.begin(),arr.end());
        
        if((maxValue - minValue)%(n-1) != 0) return false;
        
        int d = (maxValue - minValue) / (n - 1);
        
        int i = 0;
        
        for(;i<n;){
            
            if(arr[i] == minValue + (i*d)){
                i++;
                continue;
            }
            else if((arr[i]-minValue) % d != 0){
                return false;
            }
            else{
                int j = (arr[i] - minValue)/d;
                if(arr[i] == arr[j]){
                    return false;
                }
                else{
                    swap(arr[i],arr[j]);
                }
            }
            
        }
        
        return true;
    }
};