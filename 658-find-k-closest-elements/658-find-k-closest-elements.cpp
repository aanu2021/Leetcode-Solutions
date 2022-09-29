class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        
        int high = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        
        int low = high - 1;
        
        while(k--){
            
            if(high>=n || low>=0 && abs(arr[low]-x) <= abs(arr[high]-x)){
                
                low--;
                
            }
            
            else{
                
                high++;
                
            }
            
        }
        
        return vector<int>(arr.begin()+low+1,arr.begin()+high);
        
    }
};