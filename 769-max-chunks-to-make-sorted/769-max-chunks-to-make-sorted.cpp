class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int ans=0;
        
        int j=0;
        
        for(int i=0;i<arr.size();++i){
            j=max(j,arr[i]);
            if(i==j){
                ans++;
            }
        }
        
        return ans;
        
    }
};