class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        int low=0,high=n-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            int currval=nums[mid];
            
            int range=mid;
            
            if((mid+1==n || (mid+1<n && nums[mid+1]!=currval)) && (mid-1<0 || (mid-1>=0 && nums[mid-1]!=currval))){
                return nums[mid];
            } 
            
            if(mid+1<n && nums[mid+1]==currval){
                range=mid+1;
            }
            
            if(range%2!=0){
                low=range+1;
            }
            
            else{
                high=mid-1;
            }
            
        }
        
        return -1;
        
    }
};