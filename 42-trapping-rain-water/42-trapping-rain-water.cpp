class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
       
        int water_stored=0;
        
        vector<int>prefix(n,0);
        
        vector<int>suffix(n,0);
        
        prefix[0]=height[0];
        
        suffix[n-1]=height[n-1];
        
        for(int i=1;i<n;++i){
            prefix[i]=max(prefix[i-1],height[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }
        
        for(int i=0;i<n;++i){
            
            water_stored+=min(prefix[i],suffix[i])-height[i];
            
        }
        
        return water_stored;
        
    }
};