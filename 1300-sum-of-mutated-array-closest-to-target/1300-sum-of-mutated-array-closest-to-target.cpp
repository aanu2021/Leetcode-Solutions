class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int maxval=arr[n-1];
        
        vector<int>prefix(n+1,0);
        
        prefix[0]=arr[0];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        
        int mini=INT_MAX;
        int minval=INT_MAX;
        
        for(int i=0;i<=maxval;i++){
            
            int idx=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
            
            int currsum=0;
            
            if(idx==0){
                
                currsum=(n*i);
                
            }
            
            else{
                
                currsum=prefix[idx-1]+((n-idx)*i);
                
            }
            
            if(abs(currsum-target)<mini){
                
                mini=abs(currsum-target);
                minval=i;
                
            }
            
        }
        
        return minval;
        
    }
};