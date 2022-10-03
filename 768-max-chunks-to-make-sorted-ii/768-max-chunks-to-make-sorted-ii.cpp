class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>prefix(n);
        vector<int>suffix(n);
        
        prefix[0]=arr[0];
        suffix[n-1]=arr[n-1];
        
        for(int i=1;i<n;++i){
            prefix[i]=max(prefix[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],arr[i]);
        }
        
        int cuts = 1;
        
        for(int i=1;i<n;++i){
            if(prefix[i-1]<=suffix[i]){
                cuts++;
            }
        }
        
        return cuts;
        
    }
};